/*****************************************************************//**
 * \file   Constants.h
 * \brief  Various constants for the program.
 *
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#pragma once

/* Window constants */
#define WINDOW_INIT_POS  100, 100
#define WINDOW_INIT_SIZE 720, 480
#define WINDOW_TITLE     "CG Maman 15 Q2"

/* Display constants */
#define WORLD_COORD       0.0, 720.0, 480.0, 0.0  // left right bottom top

/* Cardinal spline constants */
#define CARDINAL_MATRIX_SIZE 4
#define MIN_NUM_OF_CTRL_PTS  4
#define CALCULATE_S(t)       ((1.0 - t) / 2.0)
#define U_MIN                0.0
#define U_MAX                1.0
#define U_INCREMENT          0.1
#define LINE_WIDTH           3.0f
#define POINT_COLOR          1.0, 0.0, 0.0
