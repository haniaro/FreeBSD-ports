--- tpm/tpm_emulator_extern.h.orig	2020-08-18 22:10:53 UTC
+++ tpm/tpm_emulator_extern.h
@@ -29,7 +29,7 @@ enum {
   TPM_LOG_ERROR
 };
 
-void (*tpm_log)(int priority, const char *fmt, ...);
+extern void (*tpm_log)(int priority, const char *fmt, ...);
 
 #if defined(_WIN32) || defined(_WIN64)
 #define __BFILE__ ((strrchr(__FILE__, '\\') ? : __FILE__ - 1) + 1)
@@ -44,27 +44,27 @@ void (*tpm_log)(int priority, const char *fmt, ...);
 #define error(fmt, ...) tpm_log(TPM_LOG_ERROR, "%s:%d: Error: " fmt "\n", \
                                 __BFILE__, __LINE__, ## __VA_ARGS__)
 /* initialization */
-int (*tpm_extern_init)(void);
-void (*tpm_extern_release)(void);
+extern int (*tpm_extern_init)(void);
+extern void (*tpm_extern_release)(void);
 
 /* memory allocation */
 
-void* (*tpm_malloc)(size_t size);
+extern void* (*tpm_malloc)(size_t size);
 
-void (*tpm_free)(/*const*/ void *ptr);
+extern void (*tpm_free)(/*const*/ void *ptr);
 
 /* random numbers */
 
-void (*tpm_get_extern_random_bytes)(void *buf, size_t nbytes);
+extern void (*tpm_get_extern_random_bytes)(void *buf, size_t nbytes);
 
 /* usec since last call */
 
-uint64_t (*tpm_get_ticks)(void);
+extern uint64_t (*tpm_get_ticks)(void);
 
 /* file handling */
 
-int (*tpm_write_to_storage)(uint8_t *data, size_t data_length);
-int (*tpm_read_from_storage)(uint8_t **data, size_t *data_length);
+extern int (*tpm_write_to_storage)(uint8_t *data, size_t data_length);
+extern int (*tpm_read_from_storage)(uint8_t **data, size_t *data_length);
 
 #endif /* _TPM_EMULATOR_EXTERN_H_ */
 
