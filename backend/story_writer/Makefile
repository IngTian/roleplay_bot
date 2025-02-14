# Build configuration
BUILD_DIR = cmake-build-debug

# Build targets
.PHONY: build
build:
	cmake -B $(BUILD_DIR) -G Ninja
	ninja -C $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: run-server
run-server:
	./$(BUILD_DIR)/src/server

.PHONY: run-client
run-client:
	./$(BUILD_DIR)/src/client
