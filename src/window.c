#include "GL/gl.h"
#include <GLFW/glfw3.h>

int main(void) {
  GLFWwindow* window;

  // Initialize GLFW
  if (!glfwInit())
    return -1;

  // Create the window
  window = glfwCreateWindow(640, 480, "Ant", NULL, NULL);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
