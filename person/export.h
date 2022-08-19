#ifndef STORAGE_TEST_INCLUDE_EXPORT_H_
#define STORAGE_TEST_INCLUDE_EXPORT_H_

#if !defined(TEST_EXPORT)

#if defined(TEST_SHARED_LIBRARY)
#if defined(_WIN32)

#if defined(TEST_COMPILE_LIBRARY)
#define TEST_EXPORT __declspec(dllexport)
#else
#define TEST_EXPORT __declspec(dllimport)
#endif  // defined(TEST_COMPILE_LIBRARY)

#else  // defined(_WIN32)
#if defined(TEST_COMPILE_LIBRARY)
#define TEST_EXPORT __attribute__((visibility("default")))
#else
#define TEST_EXPORT
#endif
#endif  // defined(_WIN32)

#else  // defined(TEST_SHARED_LIBRARY)
#define TEST_EXPORT
#endif

#endif  // !defined(TEST_EXPORT)

#endif  // STORAGE_TEST_INCLUDE_EXPORT_H_
