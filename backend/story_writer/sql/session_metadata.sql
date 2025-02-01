CREATE DATABASE IF NOT EXISTS roleplay_bot;
USE roleplay_bot;

CREATE TABLE session_metadata
(
    session_id    BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL COMMENT 'the session ID of the role-play story',
    system_config VARCHAR(4096)                              NOT NULL DEFAULT '' COMMENT 'the initial system config',
    temperature   DOUBLE                                     NOT NULL DEFAULT 1.0 COMMENT 'the model temperature',
    top_k         SMALLINT UNSIGNED                          NOT NULL DEFAULT 50 COMMENT 'the model top k tokens to be considered',
    top_p         DOUBLE                                     NOT NULL DEFAULT 0.9 COMMENT 'the model top_p',
    max_tokens    SMALLINT UNSIGNED                          NOT NULL DEFAULT 1024 COMMENT 'the maximum of tokens permitted for output',
    model         VARCHAR(64)                                NOT NULL DEFAULT 'Gemini_1_5_Pro' COMMENT 'the model being used',
    created_at    TIMESTAMP                                  NULL     DEFAULT CURRENT_TIMESTAMP,
    updated_at    TIMESTAMP                                  NULL     DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    deleted_at    TIMESTAMP                                  NULL     DEFAULT NULL,
    INDEX idx_session_id (session_id),
    INDEX idx_deleted_at (deleted_at)
) ENGINE = InnoDB
  DEFAULT CHARSET = utf8mb4
  COLLATE = utf8mb4_0900_ai_ci;
