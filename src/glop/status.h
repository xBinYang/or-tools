#ifndef OR_TOOLS_GLOP_STATUS_H_
#define OR_TOOLS_GLOP_STATUS_H_

#include <string>
#include "base/port.h"

namespace operations_research {
namespace glop {

// Return type for the solver functions that return "Did that work?".
// It should only be used for unrecoverable errors.
class Status {
 public:
  // Possible kinds of errors.
  enum ErrorCode {
    // Not an error. Returned on success.
    NO_ERROR = 0,

    // The LU factorization of the current basis couldn't be computed.
    ERROR_LU = 1,

    // The current variable values are out of their bound modulo the tolerance.
    ERROR_BOUND = 2,

    // A pointer argument was NULL when it shouldn't be.
    ERROR_NULL = 3,
  };

  // Creates a "successful" status.
  Status();

  // Creates a status with the specified error code and error message.
  // If "code == 0", error_message is ignored and a Status object identical
  // to Status::OK is constructed.
  Status(ErrorCode error_code, std::string error_message);

  // Improves readability but identical to 0-arg constructor.
  static const Status OK;

  // Accessors.
  ErrorCode error_code() const { return error_code_; }
  const std::string& error_message() const { return error_message_; }
  bool ok() const { return error_code_ == NO_ERROR; }

 private:
  ErrorCode error_code_;
  std::string error_message_;
};

// Returns the std::string representation of the ErrorCode enum.
std::string GetErrorCodeString(Status::ErrorCode error_code);

// Macro to simplify error propagation between function returning Status.
#define RETURN_IF_ERROR(function_call)             \
  do {                                             \
    const Status return_status = function_call;    \
    if (!return_status.ok()) return return_status; \
  } while (false)

// Macro to simplify the creation of an error.
#define RETURN_AND_LOG_ERROR(error_code, message)                          \
  do {                                                                     \
    const std::string error_message = message;                                  \
    LOG(ERROR) << GetErrorCodeString(error_code) << ": " << error_message; \
    return Status(error_code, error_message);                              \
  } while (false)

// Macro to check that a pointer argument is not null.
#define RETURN_ERROR_IF_NULL(arg)                                      \
  if (arg == nullptr) {                                                \
    const std::string variable_name = #arg;                                 \
    const std::string error_message = variable_name + " must not be null."; \
    LOG(DFATAL) << error_message;                                      \
    return Status(Status::ERROR_NULL, error_message);                  \
  }

// Macros to replace CHECK_NOTNULL() so we don't crash in production.
// Logs a FATAL message in debug mode, and an ERROR message in production.
// It is not perfect, but more robust than crashing right away.
#define RETURN_IF_NULL(x)            \
  if (x == nullptr) {                \
    LOG(DFATAL) << #x << " == NULL"; \
    return;                          \
  }

#define RETURN_VALUE_IF_NULL(x, v)   \
  if (x == nullptr) {                \
    LOG(DFATAL) << #x << " == NULL"; \
    return v;                        \
  }

}  // namespace glop
}  // namespace operations_research

#endif  // OR_TOOLS_GLOP_STATUS_H_