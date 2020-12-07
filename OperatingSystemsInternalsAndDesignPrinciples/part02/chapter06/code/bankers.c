/**
 * bankers
 * @author Clay
 * @date 2020/12/7
 */

#include <stdbool.h>
#include <limits.h>

// 资源种类
#define M 3

// 进程数量
#define N 4

typedef int vector[M];

/**
 * 状态
 */
struct State
{
    /**
     * 总资源
     */
    vector const resource;

    /**
     * 可用资源
     */
    vector available;

    /**
     * 申请资源矩阵
     */
    vector const claim[N];

    /**
     * 已分配矩阵
     */
    vector alloc[N];
};

/**
 * 分配资源，如果不安全则拒绝分配
 * @param state
 * @param id
 * @param claim
 * @return
 */
bool alloc(struct State state, size_t id, vector claim)
{
    return true;
}

/**
 * 资源分配失败时回滚
 * @param state
 * @param id
 * @param claim
 * @return
 */
bool rollback(struct State state, size_t id, vector claim)
{
    return true;
}

/**
 * 进程结束后释放所有资源
 * @param state
 * @param id
 * @return
 */
bool release(struct State state, size_t id)
{
    return true;
}

/**
 * 当前系统状态是否安全
 * @param state
 * @return
 */
bool safe(struct State state)
{
    return true;
}
