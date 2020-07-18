#pragma once

#ifndef USAR_CONSTANTS_H
#define USAR_CONSTANTS_H

inline constexpr float MAX_SPEED                = 250;
inline constexpr float SEARCH_SPEED             = 150;

inline constexpr float ALIGNMENT_WEIGHT         = 0.1;
inline constexpr float COHESION_WEIGHT          = 1.5;
inline constexpr float MAX_COHESION_WEIGHT      = 25;
inline constexpr float SEPARATION_WEIGHT        = 3.5;
inline constexpr float MAX_SEPARATION_WEIGHT    = 100;
inline constexpr float AGENT_SPACING            = 300;
inline constexpr float MAX_AGENT_SPACING        = 1000;

inline constexpr float BODY_SIZE                = 25;

inline constexpr float NEIGHBOR_RADIUS          = 1500;
inline constexpr float VISION_RADIUS            = 500;
inline constexpr float OBSTACLE_AVOID_DIST      = 100;

inline constexpr float MOVE_HEIGHT              = VISION_RADIUS * 0.85;
inline constexpr float SEARCH_HEIGHT            = 100;

inline constexpr float MIN_WP_ERR               = 25;

inline constexpr float RATE_AVOID_TASK          = 0.001;
inline constexpr float RATE_SEARCH_TASK         = 0.25;
inline constexpr float RATE_HEIGHT_TASK         = 0.25;
inline constexpr float RATE_FLOCK_TASK          = 0.35;
inline constexpr float RATE_WP_TASK             = 0.5;

#endif