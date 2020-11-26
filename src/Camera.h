#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>
#include <SDL2/SDL.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Default camera values
extern const float gYAW;
extern const float gPITCH;
extern const float gSPEED;
extern const float gSENSITIVITY;
extern const float gZOOM;

/**
* \brief Contains graphics matrices.
*
* Stores values for position and orientation of camera.
* Speed and sensitivity of camera are also configurable as public properties(unnecessary to write getters and setters - safe variables).
*/
class Camera
{
private:
	float m_Yaw;
	float m_Pitch;
	float m_FOV;
	glm::vec3 m_Position;
	glm::vec3 m_Facing;
	glm::vec3 m_Right;
	glm::vec3 m_Up;
	glm::vec3 m_WorldUp;

	int static m_ScreenWidth;
	int static m_ScreenHeight;
public:
	float m_CameraMovementSpeed;
	float m_CameraSensitivity;
	///Creates Camera object with default values
	Camera();
	///Creates Camera object with set position, facing direction, and up direction.
	Camera(glm::vec3 position, glm::vec3 facing, glm::vec3 up);
	void ProcessKeyboardInput();
	void ProcessMouseInput(float xoffset, float yoffset);
	void ProcessWindowResizing(int _screenWidth, int _screenHeight);
	void ProcessZoom();
	void UpdateCameraVectors();
	/// Generates and returns a view matrix of the current camera.
	glm::mat4 generateViewMatrix() const;
	/// Generates and returns a perspective projection matrix of the current camera.
	glm::mat4 generateProjMatrixPersp() const;
	/// Generates and returns an ortographic projection matrix of the current camera.
	glm::mat4 generateProjMatrixOrtho() const;
	glm::vec3 getPosition() const { return m_Position; }
	glm::vec3 getFacing() const { return m_Facing; }


};
