#pragma once

#include "base.h"

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/camera/camera.h>

namespace tests
{
/**
 * @class CameraSettings
 * Test setting and getting camera parameters.
 */
class CameraSettings : public TestBase
{
public:
    struct Config {
        unsigned camera_id{};
        std::string param_name{};
        std::string param_value{};

        void serialize(ConfigProvider& c)
        {
            c("camera_id", camera_id);
            c("param_name", param_name);
            c("param_value", param_value);
        }
    };

    explicit CameraSettings(const Context& context);
    ~CameraSettings() override = default;

    void run() override;

protected:
    void serialize(ConfigProvider& c) override { _config.serialize(c); }

private:
    void selectCamera();
    void getPossibleSettings();
    void getAndSetPossibleOptions();
    void setSetting();

    mavsdk::Camera::Option getOption(const std::string& setting_id);
    void setOption(const std::string& setting_id, const mavsdk::Camera::Option& option);

    mavsdk::Camera _camera;
    Config _config;
};

}  // namespace tests
