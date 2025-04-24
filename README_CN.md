<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

> [!NOTE]
>
> 最新版本：
>
> **1.2.5**
>
> 请查看 [Release](https://github.com/MobileGL-Dev/MobileGlues-release/releases)

> [!NOTE]
>
> 查看 [CompatibleShaders.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleShaders.md) 以获取兼容的 Minecraft 光影信息。
>
> 查看 [CompatibleMods.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleMods.md) 以获取兼容的 Minecraft 模组信息。
>
> 查看 [模组支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) 或 [光影支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md)，了解您的设备运行情况。

**MobileGlues**，其名称意为“(在)移动设备上，GL 使用 ES”，是一个基于 OpenGL ES 3.1 运行的 GL 实现，专为运行 Minecraft Java 版设计。

# 功能特点

1. 能够运行 Minecraft 的 [Sodium](https://github.com/CaffeineMC/sodium) 模组；

2. 能够使用 Minecraft 的 [Iris](https://github.com/IrisShaders/Iris) 模组或 [Optifine](https://optifine.net/home) 渲染大部分光影；

3. 能够兼容部分具有自定义渲染流程的 Minecraft 模组，如 [JourneyMap](https://teamjm.github.io/journeymap-docs/latest) 和 [Create](https://createmod.net)。

# 开源链接

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# 开源许可证

MobileGlues 和它的插件应用程序都以 **GNU LGPL-2.1 License** 开源.

# 加入我们

由于我们的团队规模较小，我们无法拥有所有设备并对其进行全面测试。

如果您对该项目感兴趣，请考虑通过以下方式贡献：

填写 [模组设备支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) 或 [光影设备支持列表](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md)！

我们需要您的帮助来测试不同设备对着色器和模组的兼容性！

> [!NOTE]
> 如何填写表格：
>
> 您可以：
>
> - 在表格中新增一个设备，通过在表格末尾添加新的一行。（您可以使用 `adb shell getprop ro.product.name` 获取设备代号）
> - 在表格中新增一个项目，通过在表格末尾添加新的一列。（请确保所有行格式合法！）
> - 在设备的对应单元格中标记兼容性情况：
>   - 兼容的项目标记为 ✅；
>   - 完全不兼容的项目标记为 ❌（并提交问题或提供问题链接）；
>   - 未测试的项目（不在您的模组包中/您未安装该模组）标记为 ？；
>   - 存在部分功能缺失或渲染问题的项目标记为 \*️⃣（并提交问题或提供问题链接）。
> - 如适用，您可以在 "额外驱动/插件" 列中说明您使用的除官方提供之外的其他驱动或插件（如 Turnip 驱动、ANGLE 等）。
> - 如适用，您应添加一个 `*设备代号*.md` 文件，提供更多详细信息，并在表格的最后一列附上链接。

# 第三方组件

**SPIRV-Cross** by **KhronosGroup**：[GitHub](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup**：[GitHub](https://github.com/KhronosGroup/glslang)

**GlslOptimizerV2** by **aiekick**：[GitHub](https://github.com/aiekick/GlslOptimizerV2)

**cJSON** by **DaveGamble**：[GitHub](https://github.com/DaveGamble/cJSON)

**Gson** by **Google**：[GitHub](https://github.com/google/gson)

**AndroidX Activity Compose** by **Android Open Source Project (AOSP)**：[Android Developers](https://developer.android.com/jetpack/androidx/releases/activity)
