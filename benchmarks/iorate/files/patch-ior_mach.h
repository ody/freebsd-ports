--- ior_mach.h_orig	2013-01-27 01:03:32.000000000 +0200
+++ ior_mach.h	2013-01-27 01:53:51.000000000 +0200
@@ -142,7 +142,6 @@
 #define	IOR_MAX_SEEK		(HUGE)(4398046511104LL)	/* 4 TB */
 #endif
 
-
 /************************  OS is LINUX?  ************************/
 /*
  * Since RedHat uses their own version, check for it
@@ -203,6 +202,16 @@
 #endif
 
 
+/************************  OS is FreeBSD?  ***********************/
+#ifdef  __FreeBSD__
+#include <unistd.h>
+#ifdef  IOR_LARGE_FILES
+#define HUGE                    __off_t
+#define IOR_SEEK                lseek
+#define IOR_MAX_SEEK            (HUGE)(4398046511104LL) /* 4 TB */
+#endif
+#endif
+
 /************************  OS is unknown?  ************************/
 /*
  * OK, not a known type, or did not set up large file support
@@ -240,7 +249,7 @@
 /*
  * process exit status
  */
-#if	defined( _AIX ) || defined( HPUX ) || defined( __CYGWIN__ )
+#if	defined( _AIX ) || defined( HPUX ) || defined( __CYGWIN__ ) || defined(__FreeBSD__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
