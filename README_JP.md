<!-- markdownlint-disable MD028 MD033 MD041 MD045 -->

<img src="assets/MobileGlues-icon.png" width="128">

# MobileGlues

> [!NOTE]
>
> 最新バージョン:
>
> **1.3.0·RC1**
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

# オープンソースリンク

[MobileGlues](https://github.com/MobileGL-Dev/MobileGlues)

[MobileGlues-plugin](https://github.com/MobileGL-Dev/MobileGlues-plugin)

# オープンソースライセンス

MobileGlues とそのプラグイン アプリケーションは、**GNU LGPL-2.1 ライセンス** に基づくオープン ソースです。

特に明記されていない限り、このリポジトリのコンテンツは [ECVL V1.0 ライセンス](https://github.com/MobileGL-Dev/MobileGlues-plugin/blob/main/LICENSE.md) の下で提供されています。

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

**SPIRV-Cross** by **KhronosGroup**: [github](https://github.com/KhronosGroup/SPIRV-Cross)

**glslang** by **KhronosGroup**: [github](https://github.com/KhronosGroup/glslang)

**GlslOptimizerV2** by **aiekick**: [github](https://github.com/aiekick/GlslOptimizerV2)

**cJSON** by **DaveGamble**: [github](https://github.com/DaveGamble/cJSON)

**Gson** by **Google**: [github](https://github.com/google/gson)

**AndroidX Activity Compose** by **Android Open Source Project (AOSP)**: [Android Developers](https://developer.android.com/jetpack/androidx/releases/activity)
