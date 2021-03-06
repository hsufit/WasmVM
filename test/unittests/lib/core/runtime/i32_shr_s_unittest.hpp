#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <dataTypes/Value.h>
#include <core/Runtime.h>
}
#undef _Bool

SKYPAT_F(Runtime_i32_shr_s_positive, regular)
{
    // Prepare
    Stack* stack = new_Stack();
    Value *value1 = new_i32Value(104), *value2 = new_i32Value(2);
    push_Value(stack, value1);
    push_Value(stack, value2);

    // Run
    runtime_i32_shr_s(stack);

    // Check
    Value *check = NULL;
    pop_Value(stack,&check);
    EXPECT_EQ(check->value.i32, 26);

    // Clean
    free_Value(check);
    free_Stack(stack);
}

SKYPAT_F(Runtime_i32_shr_s_negative, regular)
{
    // Prepare
    Stack* stack = new_Stack();
    Value *value1 = new_i32Value(-24), *value2 = new_i32Value(2);
    push_Value(stack, value1);
    push_Value(stack, value2);

    // Run
    runtime_i32_shr_s(stack);

    // Check
    Value *check = NULL;
    pop_Value(stack,&check);
    EXPECT_EQ(check->value.i32, -6);

    // Clean
    free_Value(check);
    free_Stack(stack);
}
