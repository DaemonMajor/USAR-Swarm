#pragma once

//#ifndef USAR_CONSTANTS_H
//#define USAR_CONSTANTS_H

inline constexpr float MAX_SPEED                = 250;
inline constexpr float SEARCH_SPEED             = 100;

inline constexpr float BODY_SIZE                = 25;

inline constexpr float NEIGHBOR_RADIUS          = 1500;
inline constexpr float VISION_RADIUS            = 500;
inline constexpr float OBSTACLE_AVOID_DIST      = 100;

inline constexpr float RATE_AVOID_TASK          = 0.005;
inline constexpr float RATE_IMAGE_SCAN          = 0.1;
inline constexpr float RATE_SEARCH_TASK         = 0.15;
inline constexpr float RATE_HEIGHT_TASK         = 0.25;
inline constexpr float RATE_FLOCK_TASK          = 0.15;
inline constexpr float RATE_WP_TASK             = 0.30;
inline constexpr float RATE_MAP_UPDATE          = 0.25;
inline constexpr float RATE_MAP_SHARE           = 3.f;

inline constexpr float WAIT_FACTOR              = 5;

inline constexpr float MOVE_HEIGHT              = VISION_RADIUS * 0.85;
inline constexpr float SEARCH_HEIGHT            = 100;

inline constexpr float MIN_WP_ERR               = 25;

inline constexpr float ALIGNMENT_WEIGHT         = 0.1;
inline constexpr float COHESION_WEIGHT          = 1.5;
inline constexpr float MAX_COHESION_WEIGHT      = 25;
inline constexpr float SEPARATION_WEIGHT        = 3.5;
inline constexpr float MAX_SEPARATION_WEIGHT    = 100;
inline constexpr float AGENT_SPACING            = 300;
inline constexpr float MAX_AGENT_SPACING        = 1000;

inline constexpr int FIB_SPHERE_FIDELITY        = 1000;

inline constexpr float MAX_SEARCH_RAD           = 2500;

inline constexpr float DETECTION_ACC            = 0.7;

inline constexpr float BATTERY_MAX              = 1800;
inline constexpr float BATTERY_RATE             = 1;


inline constexpr float CONF_INCR                = 0.15;


inline constexpr float GRID_SIZE                = 100;

//#endif