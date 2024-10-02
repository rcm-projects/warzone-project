# Warzone- Risk Game Project

## Project Overview

This project involves developing a C++ implementation of the Risk board game, compatible with the rules and map files of the "Warzone" version of Risk. The game is played on a connected graph map representing territories that players aim to conquer.

## Game Components

### Map
- Connected graph representing the world map
- Nodes are territories, edges represent adjacency
- Divided into continents (connected subgraphs)
- Each continent has a control value (bonus)

### Phases
1. **Startup Phase**
   - Determine number of players
   - Randomly assign territories
2. **Main Game Loop**
   - Reinforcement Phase
   - Orders Issuing Phase
   - Orders Execution Phase
3. **End Phase**
   - Announce winner and display statistics

### Orders
- Deploy
- Advance
- Bomb
- Blockade
- Airlift
- Negotiate

## Game Flow

1. **Startup**: Initialize players and territories
2. **Main Game Loop**: Repeats until one player controls the entire map
   - **Reinforcement**: Allocate armies to players
   - **Orders Issuing**: Players issue orders in round-robin fashion
   - **Orders Execution**: Execute orders and resolve battles
3. **End**: Determine winner and offer to play again



## Technology Stack

- **Language**: C++


## Team Members
- Ruairi Connor-Mondor (40248427
- Shant Balouzian (40226237)
- Nesrine Larbi (40079009)
- Vladimir Shterenkiker (40158317)

## Project Status

This project is currently in development. We are working on Sprint 1, focusing on map representation and basic player functionality.

