
volatile unsigned char* VGA = (volatile unsigned char*)0xB8000;

void kmain()
{
    VGA[0] = 'A';
    VGA[1] = 0x07;
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");

}