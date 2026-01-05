// Absolute minimal test - just set PA6 high forever
// This should turn on LED (or off if active low)

void test_main(void)
{
    // Enable GPIOA clock
    *((volatile unsigned int*)0x40023830) |= 0x01;
    
    // Set PA6 as output (bits 12-13 = 01)
    *((volatile unsigned int*)0x40020000) = 0x00001000;
    
    // Set PA6 high
    *((volatile unsigned int*)0x40020014) = 0x00000040;
    
    // Infinite loop
    while(1);
}
