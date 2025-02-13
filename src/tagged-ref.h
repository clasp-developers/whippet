#ifndef TAGGED_REF_H
#define TAGGED_REF_H

#include "gc-config.h"
#include "gc-ref.h"

static inline int gc_ref_is_immediate(struct gc_ref ref) {
  return GC_HAS_IMMEDIATES
    && (gc_is_immediate_tag(ref.value & (sizeof(void*) - 1)));
}
static inline int gc_ref_is_heap_object(struct gc_ref ref) {
  return !gc_ref_is_immediate(ref);
}
static inline struct gc_ref gc_ref_untag(struct gc_ref ref) {
  return gc_ref(ref.value & ~(sizeof(void*) - 1));
}

#endif // TAGGED_REF_H
