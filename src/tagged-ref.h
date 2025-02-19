#ifndef TAGGED_REF_H
#define TAGGED_REF_H

#include "gc-config.h"
#include "gc-ref.h"

static inline uintptr_t gc_ref_tag(struct gc_ref ref) {
  return ref.value & (sizeof(void*) - 1);
}
static inline int gc_ref_is_immediate(struct gc_ref ref) {
  return GC_HAS_IMMEDIATES && gc_is_immediate_tag(gc_ref_tag(ref));
}
static inline int gc_ref_is_heap_object(struct gc_ref ref) {
  return !gc_ref_is_immediate(ref);
}

static inline ptrdiff_t gc_ref_displacement(struct gc_ref ref) {
  return gc_object_displacement(ref.value);
}
static inline struct gc_ref gc_ref_undisplace(struct gc_ref ref,
                                              ptrdiff_t displacement) {
  return gc_ref(ref.value - displacement);
}
static inline struct gc_ref gc_ref_displace(struct gc_ref ref,
                                            ptrdiff_t displacement) {
  return gc_ref(ref.value + displacement);
}

#endif // TAGGED_REF_H
