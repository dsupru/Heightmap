#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SENSITIVTY = 0.1f;
const float ZOOM = 45.0f;
const float Speed = 2.5f;


// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// Eular Angles
	float Yaw;
	float Pitch;
	// Camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;
   // Next state function pointer
   void (Camera::*updateState)(float) = nullptr;

	// Constructor with vectors
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
         float speed = 2.5f,
         glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
         float yaw = YAW, 
         float pitch = PITCH) 
      : Front(glm::vec3(0.0f, 0.0f, -1.0f)), 
      MouseSensitivity(SENSITIVTY), Zoom(ZOOM)
	{
      MovementSpeed = speed;
		Position = position;
		WorldUp = up;
		Yaw = yaw;
		Pitch = pitch;
		updateCameraVectors();
	}

	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(Position, Position + Front, Up);
	}

   inline void moveForward(float deltaTime) {
		float velocity = MovementSpeed * deltaTime;
      this->Position += Front * velocity;
   }
   inline void moveBackward(float deltaTime) {
		float velocity = MovementSpeed * deltaTime;
      this->Position -= Front * velocity;
   }
   inline void moveLeft(float deltaTime) {
		float velocity = MovementSpeed * deltaTime;
      this->Position -= Right * velocity;
   }
   inline void moveRight(float deltaTime) {
		float velocity = MovementSpeed * deltaTime;
      this->Position += Right * velocity;
   }
	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = MovementSpeed * deltaTime;
      switch(direction) {
         case FORWARD:
            updateState = &Camera::moveForward;
            break;
         case BACKWARD:
            updateState = &Camera::moveBackward;
            break;
         case LEFT:
            updateState = &Camera::moveLeft;
            break;
         case RIGHT:
            updateState = &Camera::moveRight;
            break;
      }
	}

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= MouseSensitivity;
		yoffset *= MouseSensitivity;

		Yaw += xoffset;
		Pitch += yoffset;

		// Make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (Pitch > 89.0f)
				Pitch = 89.0f;
			if (Pitch < -89.0f)
				Pitch = -89.0f;
		}

		// Update Front, Right and Up Vectors using the updated Eular angles
		updateCameraVectors();
	}

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset)
	{
		if (Zoom >= 1.0f && Zoom <= 45.0f)
			Zoom -= yoffset;
		if (Zoom <= 1.0f)
			Zoom = 1.0f;
		if (Zoom >= 45.0f)
			Zoom = 45.0f;
	}

   inline void accelerate() {
      this->MovementSpeed = 6.0f;
   }
   inline void resetSpeed() {
      this->MovementSpeed = 2.5f;
   }

private:
	// Calculates the front vector from the Camera's (updated) Eular Angles
	void updateCameraVectors()
	{
		// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		front.y = sin(glm::radians(Pitch));
		front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		Front = glm::normalize(front);
		// Also re-calculate the Right and Up vector
		Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		Up = glm::normalize(glm::cross(Right, Front));
	}
};
#endif
