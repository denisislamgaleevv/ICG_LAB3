#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Shader.h"
using namespace std;
GLuint VBO;
unsigned int EBO;
unsigned int VAO;

unsigned int texture1;
Shader* ourShader;

void func() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	ourShader->use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 1);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_LINE_STRIP, 0, 6);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}
void PrintFullPath(const char* partialPath)
{
	char full[_MAX_PATH];
	if (_fullpath(full, partialPath, _MAX_PATH) != NULL)
		printf("Full path is: %s\n", full);
	else
		printf("Invalid path\n");
}
int main(int argc, char** argv)
{
	PrintFullPath(".\\");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 1024);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("textures");
	glutDisplayFunc(func);
	glClearColor(0.9, 0.8, 0.2, 1.0);
	 
	glutMainLoop();
}



