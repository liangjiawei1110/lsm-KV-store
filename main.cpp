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
    auto store = std::shared_ptr<LsmKvStore<SkipListMemTable>>(new LsmKvStore<SkipListMemTable>("./data", 2, 1));
     std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000; i++) {
        store->Set(std::to_string(i), std::to_string(i));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "insert 10000 kv into store and get the total time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;


    // spdlog::info("[Test-Result]: try to get key1's value: {}", store->Get("key1"));
    // spdlog::info("[Test-Result]: try to get key2's value: {}", store->Get("key2"));
}
