// Preprocessor Directives
#pragma once


// System Headers
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


#include <shader.hpp>
#include <camera.hpp>
#include <heightmap.hpp>


#include <iostream>

// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#ifndef _PI 
#define _PI 3.1415926535897f
#endif

using std::vector;

unsigned int  loadTexture(char const * path);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

namespace skybox {
   const size_t BoxSize = 6;
   enum class Facing : size_t{
      Right = 0,
      Left = 1,
      Top = 2,
      Bottom = 3,
      Front = 4,
      Back = 5
   };
   static const std::string faces[6] = {
      "../Project_1/Media/skybox/right.jpg",
      "../Project_1/Media/skybox/left.jpg",
      "../Project_1/Media/skybox/top.jpg",
      "../Project_1/Media/skybox/bottom.jpg",
      "../Project_1/Media/skybox/front.jpg",
      "../Project_1/Media/skybox/back.jpg"
   };
   static const vector<glm::vec3> facesLocation = {
      glm::vec3(1.0f, 0.0f, 0.0f),
      glm::vec3(-1.0f, 0.0f, 0.0f),
      glm::vec3(0.0f, 1.0f, 0.0f),
      glm::vec3(0.0f, -1.0f, 0.0f),
      glm::vec3(0.0f, 0.0f, 1.0f),
      glm::vec3(0.0f, 0.0f, -1.0f)
   };
   static const vector<glm::vec3> facesRotation = {
      glm::vec3(0.0f, _PI/2, 0.0f),
      glm::vec3(0.0f, -_PI/2, 0.0f),
      glm::vec3(_PI/2, 0.0f, -_PI/2),
      glm::vec3(-_PI/2, 0.0f, _PI/2),
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(0.0f, _PI, 0.0f)
   };

   static inline unsigned int load(vector<std::string> &faces);
   static inline void makeSurrounding(Shader& ourShader, 
         unsigned int (&texturePointers)[skybox::BoxSize]);
}





