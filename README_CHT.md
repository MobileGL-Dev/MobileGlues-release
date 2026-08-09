<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

**語言**: [English](README.md) | [简体中文](README_CN.md) | **繁體中文** | [日本語](README_JP.md)

> [!NOTE]
>
> 最新版本：
>
> **2.0.0**
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

3. 能夠兼容部分具有自定義渲染流程的 Minecraft 模組，如 [JourneyMap](https://teamjm.github.io/journeymap-docs/latest) 和 [Create](https://createmod.net)；

4. 其他易用性特性：可選用 ANGLE 作為 ES 驅動、著色器快取以加快光影包重載、支援 Minecraft 的 GPU 佔用率顯示……以及更多。

# 給光影開發者

1. MobileGlues 會自動：
   - 將桌面 GLSL 轉換為 GLSL ES
   - 移除 `layout(binding)` 語法
   - 處理 version 指令
   - 請始終顯式聲明精度：
     ```glsl
     precision highp float;
     precision highp int;
     ```

2. MobileGlues（自 V1.2.6 起）會向您的著色器注入以下巨集：

   ```glsl
   #define MG_MOBILEGLUES                   // 表示處於 MobileGlues 環境
   #define MG_MOBILEGLUES_VERSION 2000      // 版本號（例如 2000 = V2.0.0）
   ```

   可利用這些巨集編寫平台相關的邏輯：

   ```glsl
   #ifdef MG_MOBILEGLUES
       #if MG_MOBILEGLUES_VERSION >= 2000
           // MobileGlues（版本 >= V2.0.0）的邏輯
       #else
           // MobileGlues（版本 < V2.0.0）的邏輯
       #endif
   #else
       // ...
   #endif
   ```

3. 若遇到問題：
   - 請啟用 `忽略 shader/program 報錯`，並查看日誌（位於 `/sdcard/MG/latest.log`）。

# 開源鏈接

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# 開源許可證

MobileGlues 和它的插件應用程式都以 **GNU LGPL-2.1 License** 開源。

# 校驗您所下載版本的簽名

本節用於幫助您確認手中的 apk 是否為 MobileGlues 開發組發布的官方版本。

在您的 Android build-tools 中找到 `apksigner`，然後運行：

```bash
apksigner verify --print-certs path/to/MobileGlues-plugin.apk
```

它應當輸出：

```bash
Signer #1 certificate DN: CN=MGDev, OU=MGDev, O=MGDev, L=Unknown, ST=Unknown, C=CN
Signer #1 certificate SHA-256 digest: 324f4efaff81632373dec9bc714a904b64740249410b551b61805340e42ff5d5
Signer #1 certificate SHA-1 digest: 615bc8b2741c24e7e5847b0c5c1d6816d5b0763a
Signer #1 certificate MD5 digest: 320ede9d22c709fe3792c804d5e00153
```

請檢查 `certificate DN` 與 `certificate digest` 兩部分是否與上文完全一致。

如果您希望對照公鑰檔案進行校驗，我們同時提供了 `pub.cer` 與 `pub.pem`，您可以使用任何順手的工具用它們校驗您的 apk。

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
> - 如適用，您應添加一個 `*設備代號*.md` 檔案，提供更多詳細信息，並在表格的最後一列附上鏈接。

# 第三方組件

## MobileGlues

**SPIRV-Cross** by **KhronosGroup** - [Apache License 2.0](https://github.com/KhronosGroup/SPIRV-Cross/blob/master/LICENSE): [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup** - [Various Licenses](https://github.com/KhronosGroup/glslang/blob/main/LICENSE.txt): [github](https://github.com/KhronosGroup/glslang)

**cJSON** by **DaveGamble** - [MIT License](https://github.com/DaveGamble/cJSON/blob/master/LICENSE): [github](https://github.com/DaveGamble/cJSON)

**FidelityFX-FSR** by **AMD** - [MIT License](https://github.com/GPUOpen-Effects/FidelityFX-FSR/blob/master/license.txt): [github](https://github.com/GPUOpen-Effects/FidelityFX-FSR)

**Perfetto** by **Google** - [Apache License 2.0](https://github.com/google/perfetto/blob/main/LICENSE): [github](https://github.com/google/perfetto)

**xxHash** by **Yann Collet** - [BSD 2-Clause License](https://github.com/Cyan4973/xxHash/blob/dev/LICENSE): [github](https://github.com/Cyan4973/xxHash)

**flat_hash_map** by **Malte Skarupke** - [Boost Software License 1.0](https://github.com/MobileGL-Dev/flat_hash_map/blob/master/LICENSE): [github](https://github.com/MobileGL-Dev/flat_hash_map)（[skarupke/flat_hash_map](https://github.com/skarupke/flat_hash_map) 的分支，帶有使該標頭檔可在 32 位目標上包含的修復）

## MobileGlues-plugin

**Miuix** by **compose-miuix-ui** - [Apache License 2.0](https://github.com/compose-miuix-ui/miuix/blob/main/LICENSE): [github](https://github.com/compose-miuix-ui/miuix)

**Jetpack Compose** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/compose)

**AndroidX** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/androidx)

**kotlinx.coroutines** by **JetBrains** - [Apache License 2.0](https://github.com/Kotlin/kotlinx.coroutines/blob/master/LICENSE.txt): [github](https://github.com/Kotlin/kotlinx.coroutines)

**Gson** by **Google** - [Apache License 2.0](https://github.com/google/gson/blob/main/LICENSE): [github](https://github.com/google/gson)
