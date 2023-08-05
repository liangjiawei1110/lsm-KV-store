/*
 * @Author: BohanWu 819186192@qq.com
 * @Date: 2022-12-07 18:04:21
 * @LastEditors: BohanWu 819186192@qq.com
 * @LastEditTime: 2022-12-10 15:53:06
 * @FilePath: /lsm-KV-store/main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by BohanWu 819186192@qq.com, All Rights Reserved.
 */
#include "include/json.h"
#include "include/utils_for_time_operation.h"
#include <chrono>
#include <iostream>
#include "include/lsm_kv_store.h"
using json = nlohmann::json;

int main(int, char **) {
    // json j;
    // j["hello"] = "world";
    // std::cout << "in ./src/utils_for_time_operation.h, getSystemTimeInMills:" << getSystemTimeInMills()
    //           << ", j['Hello'] = " << j["hello"] << std::endl;
    // spdlog::info("Welcome to spdlog!!!!!");
     
    //create a new instance of kvstore
    const std::string FilePath = "/tmp/lsm-kv";
    auto store = std::shared_ptr<LsmKvStore<RedBlackTreeMemTable>>(new LsmKvStore<RedBlackTreeMemTable>(FilePath, 50, 1));
    //remove all data in filepath using fstream
    

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int data_size = 1e8;
    for(int i = 0; i < data_size; i++) {
        store->Set(std::to_string(i+1000000000), std::to_string(i+100000000));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "insert " << data_size<< "kv into store and get the total time: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds" << std::endl;
    exit(0);

    // spdlog::info("[Test-Result]: try to get key1's value: {}", store->Get("key1"));
    // spdlog::info("[Test-Result]: try to get key2's value: {}", store->Get("key2"));
}
