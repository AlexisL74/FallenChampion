cmake_minimum_required(VERSION 3.29)
project(FallenChampion)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/SDK/SFML-2.6.2")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${SFML_DIR}/lib/cmake/SFML)
find_package(SFML COMPONENTS network graphics window system REQUIRED)
include_directories(${SFML_DIR}/include)

add_executable(FallenChampion src/main.cpp
        src/FallenChampion.cpp
        src/FallenChampion.h
        src/engine/Scriptable.h
        src/engine/Utils.cpp
        src/engine/Utils.h
        src/engine/AnimatedSprite.cpp
        src/engine/AnimatedSprite.h
        src/battle_arena/Arena.cpp
        src/battle_arena/Arena.h
        src/battle_arena/Weapon.h
        src/battle_arena/weapon/BaseSword.cpp
        src/battle_arena/weapon/BaseSword.h
        src/engine/collision/Collider.cpp
        src/engine/collision/Collider.h
        src/engine/GameObject.cpp
        src/engine/GameObject.h
        src/battle_arena/Player.h
        src/battle_arena/Player.cpp
        src/battle_arena/Enemy.cpp
        src/battle_arena/Enemy.h
        src/battle_arena/weapon/RedMagicStaff.cpp
        src/battle_arena/weapon/RedMagicStaff.h
        src/battle_arena/Weapon.cpp
        src/battle_arena/weapon/projectiles/Projectile.h
        src/battle_arena/weapon/projectiles/FireBall.cpp
        src/battle_arena/weapon/projectiles/FireBall.h
        src/battle_arena/weapon/projectiles/Projectile.cpp
        src/battle_arena/Entity.cpp
        src/battle_arena/Entity.h
        src/battle_arena/enemies/Chort.cpp
        src/battle_arena/enemies/Chort.h
        src/battle_arena/enemies/Wogol.cpp
        src/battle_arena/enemies/Wogol.h
        src/battle_arena/enemies/Demon.cpp
        src/battle_arena/enemies/Demon.h
        src/Interfaces.cpp
        src/Interfaces.h
        src/battle_arena/Level.cpp
        src/battle_arena/Level.h
        src/battle_arena/Waves.cpp
        src/battle_arena/Waves.h
        src/engine/TextureInfo.h
        src/battle_arena/Object.cpp
        src/battle_arena/Object.h
        src/battle_arena/HUD.cpp
        src/battle_arena/HUD.h
        src/battle_arena/object/HpPotions.cpp
        src/battle_arena/object/HpPotions.h
        src/battle_arena/object/Coins.cpp
        src/battle_arena/object/Coins.h
        src/StartScreen.cpp
        src/StartScreen.h
        src/GameOver.cpp
        src/GameOver.h
)

add_custom_command(TARGET FallenChampion POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:FallenChampion>/assets)

target_link_libraries(FallenChampion sfml-graphics sfml-window sfml-system sfml-network)
