import pygame
import serial

num_br, num_bez = int(input()), int(input())

bracelet = serial.Serial(f'COM{num_br}')
bezel = serial.Serial(f'COM{num_bez}')

running = True
pygame.init()

size = width, height = 600, 600

screen = pygame.display.set_mode(size)
screen.fill((255, 255, 255))

clock = pygame.time.Clock()
fps = 30

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    screen.fill((255, 255, 255))
    pygame.display.flip()
    screen.fill((0, 0, 0))

    pygame.display.flip()
    clock.tick(fps)
