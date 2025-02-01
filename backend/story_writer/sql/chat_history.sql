CREATE DATABASE IF NOT EXISTS roleplay_bot;
USE roleplay_bot;

CREATE TABLE chat_history
(
    id         BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL COMMENT 'the primary key',
    session_id BIGINT UNSIGNED                            NOT NULL COMMENT 'the session ID of the chat',
    prompt     VARCHAR(4096)                              NOT NULL COMMENT 'the user prompt',
    response   VARCHAR(4096)                              NOT NULL COMMENT 'the llm response',
    created_at TIMESTAMP                                  NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP                                  NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    deleted_at TIMESTAMP                                  NULL DEFAULT NULL,
    FOREIGN KEY (session_id) REFERENCES roleplay_bot.session_metadata (session_id) ON DELETE CASCADE,
    INDEX idx_session_id (session_id),
    INDEX idx_deleted_at (deleted_at)
) ENGINE = InnoDB
  DEFAULT CHARSET = utf8mb4
  COLLATE = utf8mb4_0900_ai_ci;

