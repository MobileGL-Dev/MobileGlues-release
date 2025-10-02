<!-- markdownlint-disable MD033 -->

> [!WARNING]
>
> The compatible mods listed in this document are **based on testing results at the time** and do **not constitute any guarantee or promise**.
>
> Actual compatibility may vary depending on device, OpenGL ES driver, or other factors.
>
> No official support should be expected from the authors or developers, and all usage is at your own risk.

# Compatible Mods

- Sodium (Fabric) / Embeddium (NeoForge)
- Iris / OptiFine <sup>1</sup>
- Indium
- Distant Horizon
- JourneyMap
- Xaero's Minimap
- Xaero's World Map (has color issues under 0.5x zoom)
- Create 0.5.1j (Fabric / NeoForge, with flywheel batching/instancing backend supported <sup>2</sup>)
- Timeless and Classics Zero (aka. TaCZ, Fabric)
- Physics Mod
- More to discover...<sup>3</sup>

<sup>1</sup> Regarding shader compatibility, please refer to [CompatibleShaders.md](https://github.com/Swung0x48/MobileGlues-release/blob/main/CompatibleShaders.md)

<sup>2</sup> Some Mali GPUs may have rendering issues with Create's flywheel instancing backend. This is caused by a bug in Mali's ES driver. If you encounter rendering issues, please turn on ANGLE in MobileGlues app and restart launcher, or switch to other backends (using `/flywheel backend batching` or `/flywheel backend none`).

<sup>3</sup> Most of the mods that work on desktop should work on MobileGlues, but some mods may not work due to the immature status of this renderer and/or there's bugs/missing extensions in the underlying ES driver.

There can also be mods that contains native libraries that won't work on mobile platforms, but not related to renderer issues.

If you encounter any issues, please report them to the MobileGlues team, through issue of this repository, or contact the author of the launcher of your choice.
