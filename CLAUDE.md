# ZeldaLikePractice

UE 5.8 action-adventure: classic 3D Zelda (OoT/MM/TP) meets Metroid Prime. Commercial project; code must be AAA, ship quality.

## Rules
- Never commit or push. The user reviews and commits.
- Plan big features/systems fully before coding; remind the user if they skip this. Small fixes/tweaks: discuss approach, then edit.
- Never touch `Content/` with file tools (binary assets). Use `unreal-mcp` (editor must be open) or ask the user.
- Don't edit `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`, generated IDE files (`*.sln*`, `*.code-workspace`, `.vscode/*` except `mcp.json`), or engine source.
- Source and config files use CRLF line endings; preserve them.
- Keep engine defaults; no UBT/engine config overrides.

## Build
- Engine: source build at `C:\GitHub\UnrealEngine_PS`, VS 2026.
- Build: `"C:\GitHub\UnrealEngine_PS\Engine\Build\BatchFiles\Build.bat" ZeldaLikePracticeEditor Win64 Development -Project="C:\GitHub\ZeldaLikePractice\ZeldaLikePractice.uproject" -WaitMutex`
- Regen project files after adding/moving source or changing `.Build.cs`: `"C:\Users\Karat\Documents\Job Stuff\Personal Projects\Haikyo\Batch Files\GenerateAllProjectFiles.bat"`
- Build after every C++ change. If the editor is open with Live Coding, CLI builds fail, and header/reflection changes need the editor closed; tell the user.

## Code
- Epic coding standard. Headers in `Public/`, implementations in `Private/`, same subfolders.
- `TObjectPtr` for `UPROPERTY` members; raw `T*` for params/locals; `TWeakObjectPtr` for non-owning refs.
- Forward-declare in headers; include in `.cpp`. `.generated.h` last.
- Comments terse, ≤10 words.
- Ask before naming new base classes (`*_Base` pattern undecided).
- Core logic in C++. Blueprints only for assets, visuals, per-instance tweaks; subclass case by case. Never hardcode asset paths.
- Expose to editor/BP only when needed; prefer private members + getters/setters.

## Design
- Swappable Zelda-style tools (bow, bombs…) via GAS, plus a custom inventory/equipment layer that grants abilities.
- Camera: third-person + lock-on (Z-targeting) first; first-person modes for aiming and Metroid-style views.
- No Breath of the Wild / open-world systems.
- Tuning lives in data assets and editor defaults; keep systems designer-friendly.

## Collaboration
- User is a Gameplay Programmer aiming for **Senior Gameplay Engineer** (primary goal); Technical Designer is a secondary interest. Act as a senior gameplay engineer and mentor: explain reasoning and trade-offs, review to AAA standards.
- Label code **prototype** or **ship-quality**; for prototypes, note what shipping needs.
- After changes needing PIE testing, list what to check.
