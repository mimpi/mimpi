

#ifndef L_BCTES_H
#define L_BCTES_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes .................................................... */

      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node_server/c_nsver.h"
      #include "mp/xmp/map/node_server/l_nsi.h"
      #include "mp/xmp/map/node_server/l_nsinfo.h"
      #include "mp/xmp/map/node_server/l_ns/l_nodeli.h"


   /* ... Const. / Constantes ......................................... */

      #define HTTP_OK                                       \
              "HTTP/1.0 200 OK\n"                           \
              "Date: Fri, 13 Nov 1999 00:00:00 GMT\n"       \
              "Server: NodeServer/xmp\n"                    \
              "Content-type: text/html\n"                   \
              "\n"

      #define HTTP_WELCOME                                  \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<hr>\n"                                      \
              "<br>\n"                                      \
              "<h1> Welcome to NodeServer </h1>"            \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<hr>\n"                                      \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<pre>\n"

      #define HTTP_WELCOME_AUTHORS                          \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<hr>\n"                                      \
              "<br>\n"                                      \
              "<h1> Ideas, Build, Debug, ...</h1>"          \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<hr>\n"                                      \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<pre>\n"

      #define HTTP_SIGN                                     \
              "</pre>\n"                                    \
              "<br>\n"                                      \
              "<br>\n"                                      \
              "<hr>\n"                                      \
              "<br>\n"                                      \
              "<br>\n"

      #define HTTP_AUTHORS                                         \
              "<br>\n"                                             \
              "<p align=center>\n"                                 \
              "   fgarcia@laurel.datsi.fi.upm.es<br>\n"            \
              "     digital master<br>\n"                          \
              "   acaldero@laurel.datsi.fi.upm.es<br>\n"           \
              "     digital encoder<br>\n"                \
              "</p>\n"                                             \
              "<br>\n"

      #define HTTP_UNKNOW_PAGE                              \
              "<br>\n"                                      \
              "<br> Sorry, but this pages don't exist\n"    \
              "<br>\n"

      #define HTTP_NODEREF(ref,nref)                        \
              "<a href=\""ref"\">"nref"</a><br>\n"


  /* .................................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif /* L_BCTES_H */

