#ifndef VOXEL_INSTANCER_QUICK_RELOADING_CACHE_H
#define VOXEL_INSTANCER_QUICK_RELOADING_CACHE_H

#include "../../util/math/vector3i.h"
#include "../../util/memory.h"
#include "../../util/thread/mutex.h"
#include <unordered_map>

namespace zylann::voxel {

struct InstanceBlockData;

// Temporarily stores chunks that just got unloaded and are about to be saved asynchronously.
// If chunks need to be loaded again before saving has completed or even started, they will be picked from this cache
// instead. Without this, chunks could be reloaded before getting saved, leading to loss of data. As confusing as it
// sounds, this can happen because saving and loading is multi-threaded.
struct VoxelInstancerQuickReloadingCache {
	std::unordered_map<Vector3i, UniquePtr<InstanceBlockData>> map;
	Mutex mutex;
};

} // namespace zylann::voxel

#endif // VOXEL_INSTANCER_QUICK_RELOADING_CACHE_H
