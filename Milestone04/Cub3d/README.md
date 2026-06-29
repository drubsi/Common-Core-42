*This project has been created as part of the 42 curriculum by cvon-hee, drubio-s.*

## Description
**Cub3d** is an educational graphics project that implements a pseudo-3D engine using the **raycasting** technique, inspired by the classic *Wolfenstein 3D* from 1992. 

The main goal of this project is to explore and implement 2D mathematics, rendering algorithms, and event handling (keyboard/mouse) within a robust C architecture. It also involves complex parsing functionality to read, validate, and extract map configurations such as textures, colors, and layout constraints (like the flood-fill verification for closed maps).

## Instructions

### Compilation & Installation
This project leverages the MiniLibX (MLX42) graphics library and a custom libft. To compile the main game, a Makefile is provided at the root of the repository.

Dependencies required:
- `cc` / `gcc` / `clang`
- `make`
- Required libraries for MLX42 (e.g., GLFW)

To compile the mandatory part, simply run:
```bash
make
```

To compile the bonus features (which include a minimap and mouse-controlled camera rotation), run:
```bash
make bonus
```

Other available Makefile commands:
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the generated executables.
- `make re`: Fully recompiles the project from scratch.

### Execution
The executable requires a `.cub` map file as its only argument. The `maps/` directory contains several examples for testing both valid maps and edge-cases (errors).

```bash
./cub3D maps/valid.cub
```

**Controls**:
- `W`, `A`, `S`, `D`: Move the player.
- `Left Arrow` / `Right Arrow`: Rotate the camera.
- `ESC` or Window Cross: Exit the game safely.
- *(Bonus)* Mouse Movement: Rotate the camera for immersive controls.

## Git Workflow & Branching Strategy
To maintain a clean, collaborative, and organized repository, we followed a structured Git workflow tailored to how we divided the project:
- **Main Branch**: The `main` branch was kept stable, integrating major updates only when changes were verified and tested together.
- **Role-based Branches**: We split the workflow into specific branches such as `christianBACK` (focusing on backend tasks like parsing, math logic, and map validation) and `davidFRONT` (focusing on front-end tasks like raycasting, rendering, MLX integration, and events). This allowed concurrent development without stepping on each other's code.
- **Conventional Commits**: We strictly used commit prefixes to immediately identify the purpose of each change:
  - `feat:` for adding new subject requirements (e.g., separating mandatory and bonus builds, adding mouse support).
  - `fix:` and `bug:` for resolving issues and memory leaks (e.g., fixing collision offsets, resolving GNL memory leaks, fixing input hooking).
  - `refactor:` for restructuring code to comply with the 42 Norm (e.g., reducing function sizes, separating memory freeing across `free_graphics.c` and `free_game.c`, and replacing testing prints with `error_msg`).
  - `chore:` for general maintenance and cleaning up headers.

## Resources

### Documentation & Tutorials
- **Lode's Computer Graphics Tutorial - Raycasting**: The ultimate and classic reference for understanding the math behind raycasting. (https://lodev.org/cgtutor/raycasting.html)
- **MLX42 Documentation**: Used to master the modern windowing and rendering library.

### Use of Artificial Intelligence (AI)
As outlined in our `AGENT.md` configuration, AI was heavily restricted to act strictly as a **Tutor and Reviewer** rather than a code generator:
- **Code Review**: AI was used to provide feedback on correctness, safety (e.g., memory leaks, bounds), readability, and 42 Norm compliance.
- **Architecture & Planning**: AI assisted in breaking down complex tasks into verifiable milestones, such as parsing phases, flood-fill algorithm edge cases, and decoupling the rendering engine from the input logic.
- **Debugging & Hints**: When stuck on specific math or memory issues, AI provided high-level hints, pseudocode, and testing strategies (like using `valgrind --leak-check=full`) instead of full implementations. Small snippets (under 10 lines) were only used to clarify specific syntax questions or structural optimizations.
