#ifndef STORY_WRITER_GEMINI_MODEL_H
#define STORY_WRITER_GEMINI_MODEL_H

#include <story_writer.grpc.pb.h>
#include <curl/curl.h>

namespace models
{
    struct GeminiModelConfigs
    {
        roleplay_bot::ai::Model model;
        std::string system_config;
        double temperature;
        double top_p;
        uint32_t top_k;
        uint32_t max_length;
    };

    class GeminiModel
    {
    public:
        explicit GeminiModel(
            std::string &api_key,
            const GeminiModelConfigs &configs) : api_key_(api_key_),
                                                 configs_(configs),
                                                 curl_(curl_easy_init(), &curl_easy_cleanup) {};
        ~GeminiModel() = default;

        // Disable copying.
        GeminiModel(const GeminiModel &model) = delete;
        GeminiModel &operator=(const GeminiModel &model) = delete;

        // Open APIs.
    private:
        std::string api_key_;
        GeminiModelConfigs configs_;
        std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl_;
    };
}; // namespace models

#endif // STORY_WRITER_GEMINI_MODEL_H