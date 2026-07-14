//
// Created by hanji on 2025/2/9.
//

#include "settings.h"
#include "config.h"
#include "../gl/log.h"
#include "../gl/envvars.h"
#include "gpu_utils.h"
#include "../gl/getter.h"

#define DEBUG 0

global_settings_t global_settings;

void init_settings() {
#if 0
    global_settings.angle = AngleMode::Disabled;
    global_settings.ignore_error = IgnoreErrorLevel::Partial;
    global_settings.ext_gl43 = false;
    global_settings.ext_compute_shader = false;
    global_settings.max_glsl_cache_size = 30 * 1024 * 1024;
    global_settings.multidraw_mode = multidraw_mode_t::DrawElements;
    global_settings.angle_depth_clear_fix_mode = AngleDepthClearFixMode::Disabled;
    global_settings.ext_direct_state_access = true;
    global_settings.custom_gl_version = {0, 0, 0}; // will go default
    global_settings.fsr1_setting = FSR1_Quality_Preset::Disabled;

#else

    int success = initialized;
    if (!success) {
        success = config_refresh();
        if (!success) {
            LOG_V("Failed to load config. Use default config.")
        }
    }

    AngleConfig angleConfig =
        success ? static_cast<AngleConfig>(config_get_int("enableANGLE")) : AngleConfig::DisableIfPossible;
    NoErrorConfig noErrorConfig =
        success ? static_cast<NoErrorConfig>(config_get_int("enableNoError")) : NoErrorConfig::Auto;
    bool enableExtGL43 = success ? (config_get_int("enableExtGL43") > 0) : false;
    bool enableExtComputeShader = success ? (config_get_int("enableExtComputeShader") > 0) : false;
    bool enableExtTimerQuery = success ? (config_get_int("enableExtTimerQuery") > 0) : false;
    bool enableExtDirectStateAccess = success ? (config_get_int("enableExtDirectStateAccess") > 0) : false;
    AngleDepthClearFixMode angleDepthClearFixMode =
        success ? static_cast<AngleDepthClearFixMode>(config_get_int("angleDepthClearFixMode"))
                : AngleDepthClearFixMode::Disabled;
    int customGLVersionInt = success ? config_get_int("customGLVersion") : DEFAULT_GL_VERSION;
    FSR1_Quality_Preset fsr1Setting =
        success ? static_cast<FSR1_Quality_Preset>(config_get_int("fsr1Setting")) : FSR1_Quality_Preset::Disabled;

    if (customGLVersionInt < 0) {
        customGLVersionInt = 0;
    }

    size_t maxGlslCacheSize = 0;
    if (config_get_int("maxGlslCacheSize") > 0) {
        maxGlslCacheSize = success ? config_get_int("maxGlslCacheSize") * 1024 * 1024 : 0;
    }

    if (static_cast<int>(angleConfig) < 0 || static_cast<int>(angleConfig) > 3) {
        angleConfig = AngleConfig::DisableIfPossible;
    }
    if (static_cast<int>(noErrorConfig) < 0 || static_cast<int>(noErrorConfig) > 3) {
        noErrorConfig = NoErrorConfig::Auto;
    }
    if (static_cast<int>(angleDepthClearFixMode) < 0 ||
        static_cast<int>(angleDepthClearFixMode) >= static_cast<int>(AngleDepthClearFixMode::MaxValue)) {
        angleDepthClearFixMode = AngleDepthClearFixMode::Disabled;
    }
    if (customGLVersionInt > 46) {
        customGLVersionInt = 46;
    } else if (customGLVersionInt < 32 && customGLVersionInt != 0) {
        customGLVersionInt = 32;
    } else if (customGLVersionInt > 33 && customGLVersionInt < 40) {
        customGLVersionInt = 33;
    } else if (customGLVersionInt == 0) {
        customGLVersionInt = DEFAULT_GL_VERSION;
    }
    if (static_cast<int>(fsr1Setting) < 0 ||
        static_cast<int>(fsr1Setting) >= static_cast<int>(FSR1_Quality_Preset::MaxValue)) {
        fsr1Setting = FSR1_Quality_Preset::Disabled;
    }

    Version customGLVersion(customGLVersionInt);

    int isInPluginApp = 0;
    GetEnvVarInt("MG_PLUGIN_STATUS", &isInPluginApp, 0);
    int fclVersion = 0;
    GetEnvVarInt("FCL_VERSION_CODE", &fclVersion, 0);
    int zlVersion = 0;
    GetEnvVarInt("ZALITH_VERSION_CODE", &zlVersion, 0);
    int pgwVersion = 0;
    GetEnvVarInt("PGW_VERSION_CODE", &pgwVersion, 0);
    char* var = getenv("MG_DIR_PATH");
    LOG_V("MG_DIR_PATH = %s", var ? var : "(null)")

    if (isInPluginApp == 0 && fclVersion == 0 && zlVersion == 0 && pgwVersion == 0 && !var) {
        LOG_V("Unsupported launcher detected, force using default config.")
        angleConfig = AngleConfig::DisableIfPossible;
        noErrorConfig = NoErrorConfig::Auto;
        enableExtGL43 = false;
        enableExtComputeShader = false;
        enableExtTimerQuery = true;
        enableExtDirectStateAccess = true;
        maxGlslCacheSize = 0;
        angleDepthClearFixMode = AngleDepthClearFixMode::Disabled;
        fsr1Setting = FSR1_Quality_Preset::Disabled;
    }

    AngleMode finalAngleMode = AngleMode::Disabled;
    std::string gpuString = getGPUInfo();
    const char* gpu_cstr = gpuString.c_str();
    LOG_D("GPU: %s", gpu_cstr ? gpu_cstr : "(unknown)")

    int hasVk12 = hasVulkan12();
    int isQcom = isAdreno(gpu_cstr);
    int is730 = isAdreno730(gpu_cstr);
    int is740 = isAdreno740(gpu_cstr);
    int is830 = isAdreno830(gpu_cstr);
    bool isANGLESupported = checkIfANGLESupported(gpu_cstr);

    LOG_D("Has Vulkan 1.2? = %s", hasVk12 ? "true" : "false")
    LOG_D("Is Adreno? = %s", isQcom ? "true" : "false")
    LOG_D("Is Adreno 730? = %s", is730 ? "true" : "false")
    LOG_D("Is Adreno 740? = %s", is740 ? "true" : "false")
    LOG_D("Is Adreno 830? = %s", is830 ? "true" : "false")
    LOG_D("Is ANGLE supported? = %s", isANGLESupported ? "true" : "false")

    switch (angleConfig) {
    case AngleConfig::ForceDisable:
        finalAngleMode = AngleMode::Disabled;
        LOG_D("ANGLE: Force disabled");
        break;

    case AngleConfig::ForceEnable:
        finalAngleMode = AngleMode::Enabled;
        LOG_D("ANGLE: Force enabled");
        break;

    case AngleConfig::EnableIfPossible: {
        finalAngleMode = isANGLESupported ? AngleMode::Enabled : AngleMode::Disabled;
        LOG_D("ANGLE: Conditionally %s", (finalAngleMode == AngleMode::Enabled) ? "enabled" : "disabled");
        break;
    }

    case AngleConfig::DisableIfPossible:
    default:
        finalAngleMode = AngleMode::Disabled;
        break;
    }

    global_settings.angle = finalAngleMode;
    LOG_D("Final ANGLE setting: %d", static_cast<int>(global_settings.angle))
    global_settings.buffer_coherent_as_flush = (global_settings.angle == AngleMode::Disabled);

    if (global_settings.angle == AngleMode::Enabled) {
        // setenv("LIBGL_GLES", "libGLESv2_angle.so", 1);
        // setenv("LIBGL_EGL", "libEGL_angle.so", 1);
    }

    switch (noErrorConfig) {
    case NoErrorConfig::Level1:
        global_settings.ignore_error = IgnoreErrorLevel::Partial;
        LOG_D("Error ignoring: Level 1 (Partial)");
        break;

    case NoErrorConfig::Level2:
        global_settings.ignore_error = IgnoreErrorLevel::Full;
        LOG_D("Error ignoring: Level 2 (Full)");
        break;

    case NoErrorConfig::Auto:
    case NoErrorConfig::Disable:
    default:
        global_settings.ignore_error = IgnoreErrorLevel::None;
        LOG_D("Error ignoring: Disabled");
        break;
    }

    global_settings.ext_gl43 = enableExtGL43;
    global_settings.ext_compute_shader = enableExtComputeShader;
    global_settings.ext_timer_query = enableExtTimerQuery;
    global_settings.ext_direct_state_access = enableExtDirectStateAccess;
    global_settings.max_glsl_cache_size = maxGlslCacheSize;
    global_settings.angle_depth_clear_fix_mode = angleDepthClearFixMode;
    global_settings.custom_gl_version = customGLVersion;
    global_settings.fsr1_setting = fsr1Setting;
#endif

    LOG_V("[MobileGlues] Setting: enableAngle                 = %s",
          global_settings.angle == AngleMode::Enabled ? "true" : "false")
    LOG_V("[MobileGlues] Setting: ignoreError                 = %i", static_cast<int>(global_settings.ignore_error))
    LOG_V("[MobileGlues] Setting: enableExtComputeShader      = %s",
          global_settings.ext_compute_shader ? "true" : "false")
    LOG_V("[MobileGlues] Setting: enableExtGL43               = %s", global_settings.ext_gl43 ? "true" : "false")
    LOG_V("[MobileGlues] Setting: enableExtTimerQuery         = %s", global_settings.ext_timer_query ? "true" : "false")
    LOG_V("[MobileGlues] Setting: enableExtDirectStateAccess  = %s",
          global_settings.ext_direct_state_access ? "true" : "false")
    LOG_V("[MobileGlues] Setting: maxGlslCacheSize            = %i",
          static_cast<int>(global_settings.max_glsl_cache_size / 1024 / 1024))
    LOG_V("[MobileGlues] Setting: angleDepthClearFixMode      = %i",
          static_cast<int>(global_settings.angle_depth_clear_fix_mode))
    LOG_V("[MobileGlues] Setting: bufferCoherentAsFlush       = %i",
          static_cast<int>(global_settings.buffer_coherent_as_flush))
    if (global_settings.custom_gl_version.isEmpty()) {
        LOG_V("[MobileGlues] Setting: customGLVersion             = (default)");
    } else {
        LOG_V("[MobileGlues] Setting: customGLVersion             = %s",
              global_settings.custom_gl_version.toString().c_str());
    }
    LOG_V("[MobileGlues] Setting: fsr1Setting                 = %i", static_cast<int>(global_settings.fsr1_setting))

    GLVersion =
        global_settings.custom_gl_version.isEmpty() ? Version(DEFAULT_GL_VERSION) : global_settings.custom_gl_version;
}

void set_multidraw_setting() { // should be called after init_gles_target()
    multidraw_mode_t multidrawMode = static_cast<multidraw_mode_t>(config_get_int("multidrawMode"));
    if (static_cast<int>(multidrawMode) == -1) {
        multidrawMode = multidraw_mode_t::Auto;
    }
    if (static_cast<int>(multidrawMode) < 0 ||
        static_cast<int>(multidrawMode) >= static_cast<int>(multidraw_mode_t::MaxValue)) {
        multidrawMode = multidraw_mode_t::Auto;
    }
    global_settings.multidraw_mode = multidrawMode;
    std::string draw_mode_str;
    switch (global_settings.multidraw_mode) {
    case multidraw_mode_t::PreferIndirect:
        draw_mode_str = "Indirect";
        break;
    case multidraw_mode_t::PreferBaseVertex:
        draw_mode_str = "Unroll";
        break;
    case multidraw_mode_t::PreferMultidrawIndirect:
        draw_mode_str = "Multidraw indirect";
        break;
    case multidraw_mode_t::DrawElements:
        draw_mode_str = "DrawElements";
        break;
    case multidraw_mode_t::Compute:
        draw_mode_str = "Compute";
        break;
    case multidraw_mode_t::Auto:
        draw_mode_str = "Auto";
        break;
    default:
        draw_mode_str = "(Unknown)";
        global_settings.multidraw_mode = multidraw_mode_t::Auto;
        break;
    }
    LOG_V("[MobileGlues] Setting: multidrawMode               = %s", draw_mode_str.c_str())
}

void init_settings_post() {
    bool multidraw = g_gles_caps.GL_EXT_multi_draw_indirect;
    bool basevertex = g_gles_caps.GL_EXT_draw_elements_base_vertex || g_gles_caps.GL_OES_draw_elements_base_vertex ||
                      (g_gles_caps.major == 3 && g_gles_caps.minor >= 2) || (g_gles_caps.major > 3);
    bool indirect = (g_gles_caps.major == 3 && g_gles_caps.minor >= 1) || (g_gles_caps.major > 3);

    switch (global_settings.multidraw_mode) {
    case multidraw_mode_t::PreferIndirect:
        LOG_V("multidrawMode = PreferIndirect")
        if (indirect) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferIndirect;
            LOG_V("    -> Indirect (OK)")
        } else if (basevertex) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferBaseVertex;
            LOG_V("    -> BaseVertex (Preferred not supported, falling back)")
        } else {
            global_settings.multidraw_mode = multidraw_mode_t::DrawElements;
            LOG_V("    -> DrawElements (Preferred not supported, falling back)")
        }
        break;
    case multidraw_mode_t::PreferBaseVertex:
        LOG_V("multidrawMode = PreferBaseVertex")
        if (basevertex) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferBaseVertex;
            LOG_V("    -> BaseVertex (OK)")
        } else if (multidraw) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferMultidrawIndirect;
            LOG_V("    -> MultidrawIndirect (Preferred not supported, falling back)")
        } else if (indirect) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferIndirect;
            LOG_V("    -> Indirect (Preferred not supported, falling back)")
        } else {
            global_settings.multidraw_mode = multidraw_mode_t::DrawElements;
            LOG_V("    -> DrawElements (Preferred not supported, falling back)")
        }
        break;
    case multidraw_mode_t::DrawElements:
        LOG_V("multidrawMode = DrawElements")
        global_settings.multidraw_mode = multidraw_mode_t::DrawElements;
        LOG_V("    -> DrawElements (OK)")
        break;
    case multidraw_mode_t::Compute:
        LOG_V("multidrawMode = Compute")
        global_settings.multidraw_mode = multidraw_mode_t::Compute;
        LOG_V("    -> Compute (OK)")
        break;
    case multidraw_mode_t::Auto:
    default:
        LOG_V("multidrawMode = Auto")
        if (multidraw) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferMultidrawIndirect;
            LOG_V("    -> MultidrawIndirect (Auto detected)")
        } else if (indirect) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferIndirect;
            LOG_V("    -> Indirect (Auto detected)")
        } else if (basevertex) {
            global_settings.multidraw_mode = multidraw_mode_t::PreferBaseVertex;
            LOG_V("    -> BaseVertex (Auto detected)")
        } else {
            global_settings.multidraw_mode = multidraw_mode_t::DrawElements;
            LOG_V("    -> DrawElements (Auto detected)")
        }
        break;
    }
}

std::string dump_settings_string(std::string prefix) {\
    std::stringstream ss;

    ss << prefix << "Angle: " << (global_settings.angle == AngleMode::Enabled ? "Enabled" : "Disabled") << "\n";
    ss << prefix << "IgnoreError: ";
    switch (global_settings.ignore_error) {
    case IgnoreErrorLevel::None: ss << "None"; break;
    case IgnoreErrorLevel::Partial: ss << "Partial"; break;
    case IgnoreErrorLevel::Full: ss << "Full"; break;
    }
    ss << "\n";

    ss << prefix << "ExtGL43: " << (global_settings.ext_gl43 ? "True" : "False") << "\n";
    ss << prefix << "ExtComputeShader: " << (global_settings.ext_compute_shader ? "True" : "False") << "\n";
    ss << prefix << "ExtTimerQuery: " << (global_settings.ext_timer_query ? "True" : "False") << "\n";
    ss << prefix << "ExtDirectStateAccess: " << (global_settings.ext_direct_state_access ? "True" : "False") << "\n";
    ss << prefix << "MaxGlslCacheSize: " << (global_settings.max_glsl_cache_size / 1024 / 1024) << "MB\n";

    ss << prefix << "MultidrawMode: ";
    switch (global_settings.multidraw_mode) {
    case multidraw_mode_t::Auto: ss << "Auto"; break;
    case multidraw_mode_t::PreferIndirect: ss << "Indirect (glDrawElementsIndirect)"; break;
    case multidraw_mode_t::PreferBaseVertex: ss << "BaseVertex (glDrawElementsBaseVertex)"; break;
    case multidraw_mode_t::PreferMultidrawIndirect: ss << "MultidrawIndirect (glMultiDrawElementsIndirect)"; break;
    case multidraw_mode_t::DrawElements: ss << "DrawElements (glDrawElements with per-draw CPU rebase)"; break;
    case multidraw_mode_t::Compute: ss << "Compute (glDrawElements with compute-shader rebase)"; break;
    default: ss << "Unknown"; break;
    }
    ss << "\n";

    ss << prefix << "AngleDepthClearFixMode: "
       << (global_settings.angle_depth_clear_fix_mode == AngleDepthClearFixMode::Disabled ? "Disabled" : "Enabled") << "\n";

    ss << prefix << "BufferCoherentAsFlush: " << (global_settings.buffer_coherent_as_flush ? "True" : "False") << "\n";

    ss << prefix << "CustomGLVersion: "
       << ((GLVersion.toInt(2) == DEFAULT_GL_VERSION) ? "(Default)" : std::to_string(GLVersion.toInt(2))) << "\n";

    ss << prefix << "Fsr1Setting: ";

    switch (global_settings.fsr1_setting) {
    case FSR1_Quality_Preset::Disabled: ss << "Disabled"; break;
    case FSR1_Quality_Preset::UltraQuality: ss << "UltraQuality"; break;
    case FSR1_Quality_Preset::Quality: ss << "Quality"; break;
    case FSR1_Quality_Preset::Balanced: ss << "Balanced"; break;
    case FSR1_Quality_Preset::Performance: ss << "Performance"; break;
    default: ss << "Unknown"; break;
    }
    ss << "\n";

    return ss.str();
}