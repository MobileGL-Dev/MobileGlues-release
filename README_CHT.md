<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

> [!NOTE]
>
> 最新版本：
>
> **1.3.4**
>
> 請查看 [Release](https://github.com/MobileGL-Dev/MobileGlues-release/releases)

> [!NOTE]
>
> 查看 [CompatibleShaders.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleShaders.md) 以獲取兼容的 Minecraft 光影信息。
>
> 查看 [CompatibleMods.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleMods.md) 以獲取兼容的 Minecraft 模組信息。
>
> 查看 [模組支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) 或 [光影支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md)，了解您的設備運行情況。

**MobileGlues**，其名稱意為「(在)移動設備上，GL 使用 ES」，是一個基於 OpenGL ES 3.x（最佳為 3.2，最低 3.0）運行的 GL 實現，專為運行 Minecraft Java 版設計。

# 功能特點

1. 能夠運行 Minecraft 的 [Sodium](https://github.com/CaffeineMC/sodium) 模組；

2. 能夠使用 Minecraft 的 [Iris](https://github.com/IrisShaders/Iris) 模組或 [Optifine](https://optifine.net/home) 渲染大部分光影；

3. 能夠兼容部分具有自定義渲染流程的 Minecraft 模組，如 [JourneyMap](https://teamjm.github.io/journeymap-docs/latest) 和 [Create](https://createmod.net)。

# 開源連結

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# 開源許可證

MobileGlues 和它的插件應用程式都以 **GNU LGPL-2.1 License** 開源.

# 加入我們

由於我們的團隊規模較小，我們無法擁有所有設備並對其進行全面測試。

如果您對該項目感興趣，請考慮通過以下方式貢獻：

填寫 [模組設備支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) 或 [光影設備支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md)！

我們需要您的幫助來測試不同設備對著色器和模組的兼容性！

> [!NOTE]
> 如何填寫表格：
>
> 您可以：
>
> - 在表格中新增一個設備，通過在表格末尾添加新的一行。（您可以使用 `adb shell getprop ro.product.name` 獲取設備代號）
> - 在表格中新增一個項目，通過在表格末尾添加新的一列。（請確保所有行格式合法！）
> - 在設備的對應單元格中標記兼容性情況：
>   - 兼容的項目標記為 ✅；
>   - 完全不兼容的項目標記為 ❌（並提交問題或提供問題鏈接）；
>   - 未測試的項目（不在您的模組包中/您未安裝該模組）標記為 ？；
>   - 存在部分功能缺失或渲染問題的項目標記為 \*️⃣（並提交問題或提供問題鏈接）。
> - 如適用，您可以在 "額外驅動/插件" 列中說明您使用的除官方提供之外的其他驅動或插件（如 Turnip 驅動、ANGLE 等）。
> - 如適用，您應添加一個 `*設備代號*.md` 文件，提供更多詳細信息，並在表格的最後一列附上鏈接。

# 第三方組件

**SPIRV-Cross** by **KhronosGroup** - [Apache License 2.0](https://github.com/KhronosGroup/SPIRV-Cross/blob/master/LICENSE): [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup** - [Various Licenses](https://github.com/KhronosGroup/glslang/blob/main/LICENSE.txt): [github](https://github.com/KhronosGroup/glslang)

**GlslOptimizerV2** by **aiekick** - [Apache License 2.0](https://github.com/aiekick/GlslOptimizerV2/blob/master/LICENSE): [github](https://github.com/aiekick/GlslOptimizerV2)

**cJSON** by **DaveGamble** - [MIT License](https://github.com/DaveGamble/cJSON/blob/master/LICENSE): [github](https://github.com/DaveGamble/cJSON)

**OpenGL Mathematics (*GLM*)** by **G-Truc Creation** - [The Happy Bunny License](https://github.com/g-truc/glm/blob/master/copying.txt): [github](https://github.com/g-truc/glm)

**FidelityFX-FSR** by **AMD** - [MIT License](https://github.com/GPUOpen-Effects/FidelityFX-FSR/blob/master/license.txt): [github](https://github.com/GPUOpen-Effects/FidelityFX-FSR)

**Perfetto** by **Google** - [Apache License 2.0](https://github.com/google/perfetto/blob/main/LICENSE): [github](https://github.com/google/perfetto)

**xxHash** by **Yann Collet** - [BSD 2-Clause License](https://github.com/Cyan4973/xxHash/blob/dev/LICENSE): [github](https://github.com/Cyan4973/xxHash)

**Gson** by **Google** - [Apache License 2.0](https://github.com/google/gson/blob/main/LICENSE): [github](https://github.com/google/gson)

**AndroidX Activity Compose** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/androidx/releases/activity)
