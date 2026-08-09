<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

**言語**: [English](README.md) | [简体中文](README_CN.md) | [繁體中文](README_CHT.md) | **日本語**

> [!NOTE]
>
> 最新バージョン:
>
> **2.0.0**
>
> [リリース](https://github.com/MobileGL-Dev/MobileGlues-release/releases)を参照してください。

> [!NOTE]
>
> 互換性のある Minecraft のシェーダーについては、[CompatibleShaders.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleShaders.md)をご覧ください。
>
> 互換性のある Minecraft の MOD については、[CompatibleMods.md](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/CompatibleMods.md)をご覧ください。
>
> お使いのデバイスでの動作状況を確認するには、[Mod Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) または [Shader Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md) をご参照ください。

**MobileGlues**（「モバイルで、GL は ES を使用する」の意）は、ホストの OpenGL ES 3.x（ベストは 3.2、最低 3.0）上で動作する GL 実装で、Minecraft Java Edition の実行を目的としています。

# 機能

1. Minecraft の[Sodium](https://github.com/CaffeineMC/sodium) MOD を動作可能。

2. Minecraft の[Iris](https://github.com/IrisShaders/Iris) MOD または [Optifine](https://optifine.net/home) を使用して、ほとんどの Minecraft シェーダーをレンダリング可能。

3. [JourneyMap](https://teamjm.github.io/journeymap-docs/latest) や [Create](https://createmod.net) など、カスタムレンダリングルーチンを持つ一部の Minecraft MOD を動作可能。

4. その他の利便性向上機能：ES ドライバーとして ANGLE を任意で使用、シェーダーパックの再読み込みを速くするシェーダーキャッシュ、Minecraft の GPU 使用率表示への対応など。

# シェーダー開発者の方へ

1. MobileGlues は次の処理を自動的に行います：
   - デスクトップ GLSL から GLSL ES への変換
   - `layout(binding)` 構文の除去
   - version ディレクティブの処理
   - 精度は必ず明示的に宣言してください：
     ```glsl
     precision highp float;
     precision highp int;
     ```

2. MobileGlues は（V1.2.6 以降）次のマクロをシェーダーに注入します：

   ```glsl
   #define MG_MOBILEGLUES                   // MobileGlues 環境であることを示す
   #define MG_MOBILEGLUES_VERSION 2000      // バージョン番号（例：2000 = V2.0.0）
   ```

   これらのマクロを使って、プラットフォーム固有の処理を書けます：

   ```glsl
   #ifdef MG_MOBILEGLUES
       #if MG_MOBILEGLUES_VERSION >= 2000
           // MobileGlues（バージョン >= V2.0.0）向けの処理
       #else
           // MobileGlues（バージョン < V2.0.0）向けの処理
       #endif
   #else
       // ...
   #endif
   ```

3. 問題が発生した場合：
   - `シェーダー/プログラムのエラーを無視` を有効にし、ログ（`/sdcard/MG/latest.log`）を確認してください。

# オープンソースリンク

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# オープンソースライセンス

MobileGlues とそのプラグイン アプリケーションは、**GNU LGPL-2.1 ライセンス** に基づくオープン ソースです。

# リリースの署名を確認する

この節は、お手元の apk が MobileGlues 開発チームによる公式リリースかどうかを確認するための手引きです。

Android build-tools に含まれる `apksigner` を見つけ、次のコマンドを実行してください：

```bash
apksigner verify --print-certs path/to/MobileGlues-plugin.apk
```

次のように出力されるはずです：

```bash
Signer #1 certificate DN: CN=MGDev, OU=MGDev, O=MGDev, L=Unknown, ST=Unknown, C=CN
Signer #1 certificate SHA-256 digest: 324f4efaff81632373dec9bc714a904b64740249410b551b61805340e42ff5d5
Signer #1 certificate SHA-1 digest: 615bc8b2741c24e7e5847b0c5c1d6816d5b0763a
Signer #1 certificate MD5 digest: 320ede9d22c709fe3792c804d5e00153
```

`certificate DN` と `certificate digest` の部分が上記と完全に一致するか確認してください。

公開鍵ファイルと照合したい場合のために、`pub.cer` と `pub.pem` も提供しています。お好みのツールで apk をこれらと照合できます。

# コール・トゥ・アクション

私たちは小規模なチームのため、すべての異なるデバイスを所有し、それらで完全なテストを行うことができません。

このプロジェクトに興味がある方は、ぜひ以下の方法でプロジェクトに貢献してください！

[Mod Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ModSupportMatrix.md) や [Shader Support Matrix](https://github.com/MobileGL-Dev/MobileGlues-release/blob/main/ShaderSupportMatrix.md) を記入してください！

私たちは、シェーダーや MOD の互換性を確認し、多種多様なデバイスでテストするために、皆さんの協力を必要としています！

> [!NOTE]  
> テーブルの記入方法
>
> 以下の方法でテーブルを編集できます：
>
> - 新しいデバイスを追加する場合、新しい行を追加してください。（デバイスのコードネームは `adb shell getprop ro.product.name` で取得可能）
> - 新しい項目を追加する場合、新しい列を追加してください。（すべての行で適切に列を追加してください）
> - デバイスでの互換性を示す場合、以下の記号を使用してください：
>   - ✅（チェックマーク）：互換性あり
>   - ❌（バツ）：完全に非互換（問題を報告/リンクを添付）
>   - ？（クエスチョンマーク）：未検証（MOD パックに含まれていない/インストールしていない）
>   - \*️⃣（アスタリスク）：動作するが、一部の機能が欠落またはグラフィックの不具合あり（問題を報告/リンクを添付）
> - 必要に応じて、「Additional Drivers/Plugins in use（使用中の追加ドライバー/プラグイン）」の列に、ベンダー提供以外の追加ドライバーやプラグイン（例: Turnip ドライバー、ANGLE など）を記入してください。
> - 必要に応じて `*device_codename*.md` というファイルを作成し、追加情報を提供し、最後の列にリンクを記載してください。

# サードパーティコンポーネント

## MobileGlues

**SPIRV-Cross** by **KhronosGroup** - [Apache License 2.0](https://github.com/KhronosGroup/SPIRV-Cross/blob/master/LICENSE): [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup** - [Various Licenses](https://github.com/KhronosGroup/glslang/blob/main/LICENSE.txt): [github](https://github.com/KhronosGroup/glslang)

**cJSON** by **DaveGamble** - [MIT License](https://github.com/DaveGamble/cJSON/blob/master/LICENSE): [github](https://github.com/DaveGamble/cJSON)

**FidelityFX-FSR** by **AMD** - [MIT License](https://github.com/GPUOpen-Effects/FidelityFX-FSR/blob/master/license.txt): [github](https://github.com/GPUOpen-Effects/FidelityFX-FSR)

**Perfetto** by **Google** - [Apache License 2.0](https://github.com/google/perfetto/blob/main/LICENSE): [github](https://github.com/google/perfetto)

**xxHash** by **Yann Collet** - [BSD 2-Clause License](https://github.com/Cyan4973/xxHash/blob/dev/LICENSE): [github](https://github.com/Cyan4973/xxHash)

**flat_hash_map** by **Malte Skarupke** - [Boost Software License 1.0](https://github.com/MobileGL-Dev/flat_hash_map/blob/master/LICENSE): [github](https://github.com/MobileGL-Dev/flat_hash_map)（[skarupke/flat_hash_map](https://github.com/skarupke/flat_hash_map) のフォークで、32 ビット環境でもヘッダーを include できるようにする修正を含みます）

## MobileGlues-plugin

**Miuix** by **compose-miuix-ui** - [Apache License 2.0](https://github.com/compose-miuix-ui/miuix/blob/main/LICENSE): [github](https://github.com/compose-miuix-ui/miuix)

**Jetpack Compose** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/compose)

**AndroidX** by **Android Open Source Project (AOSP)** - [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.txt): [Android Developers](https://developer.android.com/jetpack/androidx)

**kotlinx.coroutines** by **JetBrains** - [Apache License 2.0](https://github.com/Kotlin/kotlinx.coroutines/blob/master/LICENSE.txt): [github](https://github.com/Kotlin/kotlinx.coroutines)

**Gson** by **Google** - [Apache License 2.0](https://github.com/google/gson/blob/main/LICENSE): [github](https://github.com/google/gson)
