#ifndef HEADER_CURL_TOOL_METALINK_H
#define HEADER_CURL_TOOL_METALINK_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2012, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include "tool_setup.h"

#include <metalink/metalink_parser.h>

#include "tool_cfgable.h"

struct metalinkfile {
  struct metalinkfile *next;
  metalink_file_t *file;
};

struct metalink {
  struct metalink *next;
  metalink_t* metalink;
};

struct metalinkfile *new_metalinkfile(metalink_file_t *metalinkfile);

struct metalink *new_metalink(metalink_t *metalink);

int operatemetalink(CURL *curl,
                    struct getout *urlnode,
                    long retry_sleep_default,
                    struct OutStruct outs,
                    struct OutStruct heads,
                    char *outfiles,
                    struct Configurable *config);

void clean_metalink(struct Configurable *config);

#endif /* HEADER_CURL_TOOL_METALINK_H */