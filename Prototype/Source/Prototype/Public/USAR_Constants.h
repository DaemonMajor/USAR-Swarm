#pragma once

//#ifndef USAR_CONSTANTS_H
//#define USAR_CONSTANTS_H

inline constexpr char* LOG_DIR                  = "B:/Documents/Strathclyde/Master's Thesis/USAR_Swarm/";

inline constexpr float SIM_LENGTH               = 10 * 60;
inline constexpr float SIM_SAVE_RATE            = 1 * 60;
inline constexpr int GRID_SIZE                  = 50;

inline constexpr float FLOCK_SIZE               = 15;

inline constexpr float MAX_SPEED                = 250;
inline constexpr float SEARCH_SPEED             = 100;

inline constexpr float BODY_SIZE                = 25;

inline constexpr float NEIGHBOR_RADIUS          = 750;
inline constexpr float VISION_RADIUS            = 500;
inline constexpr float OBSTACLE_AVOID_DIST      = 100;
inline constexpr float SAFETY_DIST              = 10;

inline constexpr float RATE_AVOID_TASK          = 0.005;
inline constexpr float RATE_HEIGHT_TASK         = 0.5;
inline constexpr float RATE_FLOCK_TASK          = 0.15;
inline constexpr float RATE_WP_TASK             = 0.30;
inline constexpr float RATE_MAP_UPDATE          = 0.25;
inline constexpr float RATE_MAP_SHARE           = 1.f;

inline constexpr float RATE_BBSEARCH_R          = 0.25;
inline constexpr float RATE_BBSEARCH_E          = 3;
inline constexpr float RATE_RWSEARCH            = 0.15;
inline constexpr float RWSEARCH_LENGTH          = 60 * 5;
inline constexpr float RW_MOMENTUM              = 0.5;

inline constexpr float WAIT_FACTOR              = 5;

inline constexpr float MOVE_HEIGHT              = VISION_RADIUS * 0.85;
inline constexpr float SEARCH_HEIGHT            = 100;

inline constexpr float WP_TOLERANCE             = 15;
inline constexpr float CHANCE_FOLLOW            = 0.65;

inline constexpr float ALIGNMENT_WEIGHT         = 0.1;
inline constexpr float COHESION_WEIGHT          = 0.75;
inline constexpr float MAX_COHESION_WEIGHT      = 25;
inline constexpr float SEPARATION_WEIGHT        = 3.5;
inline constexpr float MAX_SEPARATION_WEIGHT    = 3.5 + 5 * 60/3 * 2.5;
inline constexpr float AGENT_SPACING            = 500;
inline constexpr float MAX_AGENT_SPACING        = NEIGHBOR_RADIUS;

inline constexpr int FIB_SPHERE_FIDELITY        = 1000;

inline constexpr float MAX_SEARCH_RAD           = 2500;

inline constexpr float DETECTION_ACC            = 0.7;

inline constexpr float BATTERY_MAX              = 1800;
inline constexpr float BATTERY_RATE             = 1;


inline constexpr float CONF_INCR                = 0.01;


enum GridDisp {
    Point,
    Box
};

enum SearchBehavior {
    None,
    Spiral,
    Radial,
    RandomWalk,
    Frontier
};

//#endif