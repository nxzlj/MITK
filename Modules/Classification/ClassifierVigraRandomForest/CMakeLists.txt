MITK_CREATE_MODULE(
  DEPENDS MitkClassificationCore MitkClassificationUtilities
  AUTOLOAD_WITH MitkCore
  PACKAGE_DEPENDS
    PUBLIC Boost
    PRIVATE Vigra
  WARNINGS_AS_ERRORS
)

add_subdirectory(test)
