//
// Created by kai.l on 2021/3/28.
//
#ifndef JNIDEMO_DEBUG_H
#define JNIDEMO_DEBUG_H

#include <stdio.h>
#include <errno.h>
#include <android/log.h>

#define  LOG_TAG    "AndroidLog"
#define  ALOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__ )
#define  ALOGI(...)  __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__ )
#define  ALOGW(...)  __android_log_print(ANDROID_LOG_WARN,  LOG_TAG, __VA_ARGS__ )
#define  ALOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

enum {
    LOG_LEVEL_NONE = 0,
    LOG_LEVEL_ERR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4
};

#define LOG_TEXT_MAX_LENGTH        (1024)  //  单条日志大小
#define LOG_FILE_MAX_SIZE    (1024*1024*5) //  文件最大为5MB

/**
    * 初始化日志选项
    * @param pFilePath  日志路径
    * @param filename   日志名称
    * @param logLevel   日志级别
    * @param printScreen 打印的级别
    * @return
    */
int _LogInit(const char *pFilePath, const char *filename, int logLevel, int printScreen);

/**
 * 写日志
 * @param level
 * @param strFormat
 * @param ...
 */
void WriteTextLog(int level, const char *strFormat, ...);

/**
 * 向文件中写入日志
 * @param level
 * @param log
 */
void WriteTextLogBottom(int level, const char *log);

/**
 * 关闭日志库
 */
void _LogClose();

#endif //JNIDEMO_DEBUG_H
