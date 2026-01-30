#include "../include/glad/glad.h"

#include "GL/gl.h"
#include <GLFW/glfw3.h>
#include "shader_s.h"

#include <iostream>

int WIDTH = 400;
int HEIGHT = 400;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  WIDTH = width;
  HEIGHT = height;
}

int main(void) {
  GLFWwindow* window;

  // Initialize GLFW
  if (!glfwInit())
    return -1;

  // Create the window
  window = glfwCreateWindow(400, 400, "Ant", NULL, NULL);
  if (!window) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



  Shader Shader("../src/shader.vs", "../src/shader.fs");


  // Plane definition
  float vertices[] = {
    // positions         // texture 
   -1.0f, -1.0f, 0.0f,  -1.0f, -1.0f,  // bottom left
    1.0f, -1.0f, 0.0f,  -1.0f,  1.0f,  // bottom right
   -1.0f,  1.0f, 0.0f,   1.0f, -1.0f,  // top left
    1.0f,  1.0f, 0.0f,   1.0f,  1.0f,  // top right
  };

  unsigned int indices[] = {
    0, 1, 3,  // first triangle
    0, 2, 3   // second triangle
  };

  int PixelBufferSize = WIDTH * HEIGHT * 3;
  GLubyte* PixelBuffer = new GLubyte[PixelBufferSize];
  for (int i = 0; i < PixelBufferSize; i += 3) {
    PixelBuffer[i]     = 0;
    PixelBuffer[i + 1] = 0;
    PixelBuffer[i + 2] = 0;
  }

  PixelBuffer[729] = 255;
  PixelBuffer[730] = 255;
  PixelBuffer[731] = 255;

  unsigned int textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);

  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
  glGenerateMipmap(GL_TEXTURE_2D);


  // Square init
  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  // Bind vertex array object
  glBindVertexArray(VAO);

  // Copy vertices array to buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // Set vertex attribute pointers
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Texture pointers
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1); 


  // Main loop
  while (!glfwWindowShouldClose(window)) {
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Shader.use();
    
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
