# ZeldaLikePractice

A Zelda-like action game built in Unreal Engine 5.8.

## Git

- Never commit or push. Stage and edit files as needed, but leave the commit to the user so they can review the changes first.

## Engine and Build

- The engine is a **source build** at `C:\GitHub\UnrealEngine_PS` (UE 5.8), not a launcher install.
- Build the editor target:
  ```
  "C:\GitHub\UnrealEngine_PS\Engine\Build\BatchFiles\Build.bat" ZeldaLikePracticeEditor Win64 Development -Project="C:\GitHub\ZeldaLikePractice\ZeldaLikePractice.uproject" -WaitMutex
  ```
- Regenerate project files (Visual Studio `.slnx` and the VS Code workspace) with:
  ```
  "C:\Users\Karat\Documents\Job Stuff\Personal Projects\Haikyo\Batch Files\GenerateAllProjectFiles.bat"
  ```
  Regenerate after adding, removing or moving source files, or after changing `.Build.cs`/`.Target.cs`.
- **Live Coding:** command-line builds fail while the editor is open with Live Coding enabled. Live Coding can't apply header or reflection changes (`UCLASS`, `USTRUCT`, `UPROPERTY`, `UFUNCTION`, new members). Those need the editor closed and a full build. Tell the user when a change needs that.

## Assets

- `.uasset` and `.umap` files are binary. Never read, edit, move or delete anything under `Content/` with file tools.
- Work with assets, Blueprints and levels through the `unreal-mcp` server, or ask the user to make the change in the editor.

## Off-Limits

- Don't edit generated or cached folders: `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`.
- Don't edit generated IDE files: `*.slnx`, `*.code-workspace`, and the generated files in `.vscode/` (everything except `mcp.json`). Regenerate them instead.
- Don't modify engine source in `C:\GitHub\UnrealEngine_PS` unless the user explicitly asks.

## Unreal MCP

- The `unreal-mcp` server (config in `.vscode/mcp.json`) runs at `http://127.0.0.1:8000/mcp`. It comes from the `ModelContextProtocol` plugin and is only available while the editor is open.
- If it fails to connect, the editor probably isn't running. Tell the user rather than working around it.

## Code Layout

- One runtime module, `ZeldaLikePractice`, in `Source/ZeldaLikePractice/`.
  - Headers go in `Public/` and implementations in `Private/`, mirroring the same subfolders (e.g. `Public/Core/` ↔ `Private/Core/`).
  - `Core/` holds framework classes (game mode, etc.).
  - Base classes: `Actor_Base`, `Pawn_Base`, `Character_Base`, `PlayerCharacter_Base`.
  - Input uses Enhanced Input, configured through `PlayerInputConfig`.
- Module dependencies are declared in `Source/ZeldaLikePractice/ZeldaLikePractice.Build.cs`. Add a module there before using its headers.
- Targets: `ZeldaLikePractice` (game) and `ZeldaLikePracticeEditor` (editor).

## Coding Conventions

- Follow the Epic coding standard (type prefixes `A`/`U`/`F`/`E`/`I`/`T`, `b` for bools, PascalCase).
- Class naming: the `*_Base` pattern is undecided. Ask before naming new base classes.
- Pointers:
  - `UPROPERTY` member pointers to UObjects use `TObjectPtr<T>`.
  - Function parameters, return values and locals use raw `T*`.
  - Non-owning references that shouldn't keep an object alive use `TWeakObjectPtr<T>`.
- Comments: terse, 10 words or fewer where possible.
- Includes:
  - In headers, forward-declare classes used only as pointers or references; include them in the `.cpp`.
  - Include in the header only what it needs in full: base classes, by-value members, and types whose members are used inline.
  - `.generated.h` is always the last include in a header.

## C++ and Blueprint

- All core logic lives in C++. Blueprints are only for visual and per-instance tweaks.
- Create Blueprint subclasses case by case, typically when a class needs asset references (meshes, anim BPs, input assets, sounds, VFX) or designer-tuned variants. Logic-only classes stay C++-only.
- Assign assets in Blueprint subclasses or data assets. Don't hardcode asset paths in C++.
- Expose properties and functions to the editor or Blueprint only when needed. Prefer private members with getters/setters when changes need to be controlled.

## Game Design

- Classic 3D Zelda (Ocarina of Time, Majora's Mask, Twilight Princess) mixed with Metroid Prime, plus influence from their 2D entries. Not Breath of the Wild; avoid open-world/sandbox systems.
- The player swaps between Zelda-style tools (bow, bombs, etc.).
- Camera: third-person exploration and lock-on (Z-targeting) is the main focus. First-person modes are also needed, such as aiming tools and Metroid Prime-style views.
- Abilities and tools use the Gameplay Ability System (GAS), with a custom inventory/equipment layer that grants tool abilities. Plan the design before implementing.
- Code and logic should be AAA quality and shippable; this is a commercial project.

## Workflow

- **Plan first.** Big features or systems get a full planning discussion before any code. Remind the user of this if they jump straight to a large change.
- Small tasks (fixes, tweaks): discuss the approach before editing; no full plan needed.
- After C++ changes, build to confirm they compile (skip if the editor is open with Live Coding; tell the user instead).
- When a change needs testing in PIE, say so and list what to check.
- This is also a learning project. Act as a senior engineer and mentor: explain the reasoning and trade-offs behind changes and patterns, and review code to AAA standards.
- Label code as **prototype** (quick, to test an idea) or **ship-quality**. For prototypes, note what it would take to ship.
- Keep the designer side in mind: tuning lives in data assets and editor-exposed defaults, and systems should be easy for a designer to work with.
