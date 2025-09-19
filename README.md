<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

**Language**: [简体中文](README_CN.md) | [繁體中文](README_CHT.md) | [日本語](README_JP.md)

<a href="https://www.buymeacoffee.com/Swung0x48" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

> [!NOTE]
>
> The latest version:
>
> **1.3.2·RC1**
>
> See [Releases](https://github.com/MobileGL-Dev/MobileGlues-release/releases)

> [!NOTE]
>
> See [CompatibleShaders.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleShaders.md) to see compatible Minecraft shaders.
>
> See [CompatibleMods.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleMods.md) to see compatible Minecraft mods.
>
> See [Mod Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) or [Shader Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md) to check how your device works out.

**MobileGlues**, which stands for "(on) Mobile, GL uses ES", is a GL implementation running on top of host OpenGL ES 3.x (best on 3.2, minimum 3.0), with running Minecraft: Java Edition in mind.

# Features

1. Capable of running Minecraft [Sodium](https://github.com/CaffeineMC/sodium) mod;

2. Capable of rendering most minecraft shaders with Minecraft [Iris](https://github.com/IrisShaders/Iris) mod or [Optifine](https://optifine.net/home).

3. Capable of running some Minecraft mods with custom rendering routines, such as [JourneyMap](https://teamjm.github.io/journeymap-docs/latest) and [Create](https://createmod.net).

4. Additional QoL features: optional ANGLE as ES driver, shader caching for fast shaderpack reloads, supports Minecraft GPU% reporting, ...and more!

# Open Source Links

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# License

MobileGlues and its plugin application are licensed under **GNU LGPL-2.1 License**.

# Call to Action

Since we are a small team, we cannot own every distinct device and do through tests on them.

If you are interested in this project, please consider contributing to the project by:

Filling out the [mod support matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) or [shader support matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md)!

We need your help to test the compatibility of shaders and mods, and a broad variety of devices!

> [!NOTE]
> How to fill out the table
>
> You may:
>
> - Add a new device to the table, by appending a new row to the table. (You can get device codename from `adb shell getprop ro.product.name`)
> - Add a new item to the table, by appending a new column to the table. (Make sure you have modify all the rows to add the column!)
> - Fill out the table with the compatibility of the item on the device, by marking the cell with
>   - a checkmark (✅) if the item is compatible,
>   - or a cross (❌) if the item is fully not compatible (and file an issue/link to the issue).
>   - If the item is not tested (not included in your modpack/you do not install this mod), mark the cell with a question mark (?).
>   - a asterisk (\*️⃣) if the item is working, but have missing features and/or have graphical glitches (and file an issue/link to the issue).
> - If applicable, you may want to mention what additional drivers/plugins rather than the one vendor provides, are in use (such as turnip drivers, ANGLE, etc.) in the "Additional Drivers/Plugins in use" column.
> - If applicable, you should add a file named `*device_codename*.md`, to provide additional information, and put the link in the last column.

# Third party components

**SPIRV-Cross** by **KhronosGroup** - [Apache License 2.0](https://github.com/KhronosGroup/SPIRV-Cross/blob/master/LICENSE): [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup** - [Various Licenses](https://github.com/KhronosGroup/glslang/blob/main/LICENSE.txt): [github](https://github.com/KhronosGroup/glslang)

**GlslOptimizerV2** by **aiekick** - [Apache License 2.0](https://github.com/aiekick/GlslOptimizerV2/blob/master/LICENSE): [github](https://github.com/aiekick/GlslOptimizerV2)

**cJSON** by **DaveGamble** - [MIT License](https://github.com/DaveGamble/cJSON/blob/master/LICENSE): [github](https://github.com/DaveGamble/cJSON)

**OpenGL Mathematics (*GLM*)** by **G-Truc Creation** - [The Happy Bunny License](https://github.com/g-truc/glm/blob/master/copying.txt): [github](https://github.com/g-truc/glm)

**FidelityFX-FSR** by **AMD** - [MIT License](https://github.com/GPUOpen-Effects/FidelityFX-FSR/blob/master/license.txt): [github](https://github.com/GPUOpen-Effects/FidelityFX-FSR) 

**Gson** by **Google** - [Apache License 2.0](https://github.com/google/gson/blob/main/LICENSE): [github](https://github.com/google/gson)

**AndroidX Activity Compose** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/androidx/releases/activity)
