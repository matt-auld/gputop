/*
 * GPU Top
 *
 * Copyright (C) 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#pragma once

#include <pthread.h>

#include "gputop-list.h"

#ifdef SUPPORT_WEBUI
#include "gputop.pb-c.h"
#endif

extern pthread_once_t gputop_log_init_once;
extern pthread_rwlock_t gputop_log_lock;
extern int gputop_log_len;
extern gputop_list_t gputop_log_entries;

enum gputop_log_level {
    GPUTOP_LOG_LEVEL_HIGH = 1,
    GPUTOP_LOG_LEVEL_MEDIUM,
    GPUTOP_LOG_LEVEL_LOW,
    GPUTOP_LOG_LEVEL_NOTIFICATION,
};

struct gputop_log_entry {
    gputop_list_t link;
    char *msg;
    int level;
};

void gputop_log_init(void);
void gputop_log(int level, const char *message, int len);

#ifdef SUPPORT_WEBUI
Gputop__Log *gputop_get_pb_log(void);
void gputop_pb_log_free(Gputop__Log *log);
#endif
