#ifndef VOXEL_INSTANCER_TASK_OUTPUT_QUEUE_H
#define VOXEL_INSTANCER_TASK_OUTPUT_QUEUE_H

#include "../../util/math/transform3f.h"
#include "../../util/math/vector3i.h"
#include "../../util/thread/mutex.h"
#include <cstdint>
#include <vector>

namespace zylann::voxel {

struct VoxelInstanceLoadingTaskOutput {
	Vector3i render_block_position;
	uint8_t layer_id;
	// Tells which parts of the block contain edited data (non-generated).
	// When data chunks are half the size of render chunks, this is 8 bits in XYZ order.
	uint8_t edited_mask;
	std::vector<Transform3f> transforms;
};

struct VoxelInstancerTaskOutputQueue {
	std::vector<VoxelInstanceLoadingTaskOutput> results;
	Mutex mutex;
};

} // namespace zylann::voxel

#endif // VOXEL_INSTANCER_TASK_OUTPUT_QUEUE_H
