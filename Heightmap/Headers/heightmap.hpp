#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <iostream>

#include <shader.hpp>

// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
#include <stb_image.h>
#ifndef _PI 
#define _PI 3.14159265358979323846264338327950f
#endif

struct Vertex {
	// position
	glm::vec3 Position;
	// texCoords
	glm::vec2 TexCoords;
};

// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Heightmap
{
public:
	//heightmap attributes
	int width, height;

	// VAO for heightmap
	unsigned int VAO;

	// pointer to data - data is an array so can be accessed by data[x]. 
	//       - this is an uint8 array (so values range from 0-255)
	unsigned char *data;

	// heightmap vertices
	std::vector<Vertex> vertices;
	// indices for EBO
	std::vector<unsigned int> indices;


	// constructor
	Heightmap(const char* heightmapPath)
	{
		// load heightmap data
		load_heightmap(heightmapPath);
		// create heightmap verts from the image data - (you have to write this)
		create_heightmap();
		// free image data
		stbi_image_free(data);
		// create_indices - create the indices array (you have to write this)
		//  This is an optional step
      //  you can ignore this if you want to just create all the triangles rather than
		//     using this to index it.
		create_indices();
		// setup the VBO, VAO, and EBO and send the information to OpenGL (you need to write this)
		setup_heightmap();
	}

	// render the heightmap mesh (you need to write this)
	void Draw(Shader shader, unsigned int textureID)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, textureID);

      glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -20.0f, 0.0f));
      model = glm::rotate(model, -_PI/2, glm::vec3(1.0f, 0.0f, 0.0f));
      model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
      model = glm::rotate(model, _PI/2, glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, glm::vec3(100.0f, 100.0f, 24.0f));
      shader.setMat4("model", model);
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 128 * sizeof(Vertex) * sizeof(vertices) * sizeof(float));
	}

private:

	unsigned int VBO, EBO;

	// Load the image data
	void load_heightmap(const char* heightmapPath)
	{
		int nrChannels;
		data = stbi_load(heightmapPath, &width, &height, &nrChannels, 0);
		if (!data)
		{
			std::cout << "Failed to load heightmap" << std::endl;
		}

	}
	
   Vertex make_vertex(int x, int y) {
	   Vertex v;
	   //XYZ coords
	   v.Position.x = float(x)/width -0.5f;
	   v.Position.y = float(y)/height -0.5f;
	   v.Position.z = float(data[x*height + y]) / 255.0f;

	   //Texture Coords
	   v.TexCoords.x = float(x)/width;
	   v.TexCoords.y = float(y)/width;

	   return v;
	}
	

	// convert heightmap to floats, set position and texture vertices using the subfunction make_vertex
	void create_heightmap()
	{
      for (int i = 0; i < height -1; i++) {
         for (int j = 0; j < width -1; j++) {
            vertices.push_back(make_vertex(j, i));
            vertices.push_back(make_vertex(j+1, i));
            vertices.push_back(make_vertex(j, i+1));
            vertices.push_back(make_vertex(j+1, i));
            vertices.push_back(make_vertex(j, i+1));
            vertices.push_back(make_vertex(j+1, i+1));
         }
      }
	}
	// create the indicies array for the EBO 
   // (so what indicies correspond with triangles to for rendering)
	//  This is an optional step
   //  You can ignore this if you want to just create all the triangles rather than
	//     using this to index it.
	void create_indices()
	{
	}

	// create buffers/arrays for the VAO, VBO, and EBO 
	// Notes
	//  -  sizeof(Vertex) returns the size of the vertex
	//  -  to get the pointer the underlying array, you can use "&vertices[0]"
	void setup_heightmap() {
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), &vertices[0], GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
      glEnableVertexAttribArray(1);
	}

};
#endif
