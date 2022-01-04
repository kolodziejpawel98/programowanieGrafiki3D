# Zadania

## House -- Pyramid

OK

## Resize 
20.12.2021 19:21:33 
Jednak nie OK używa Pan polecenia glBufferData w funkcji frame. To oznacza, że w każdej klatcer alokuje Pan n owy bufor. 

3.01.2022 17:00:27 
Bufor uniform nie jest bindowany przed użyciem w funckji frame. 


## Zoom -- CameraMovement 

20.12.2021 19:21:33 
Jednak nie OK używa Pan polecenia glBufferData w funkcji frame. To oznacza, że w każdej klatcer alokuje Pan n owy bufor. 

3.01.2022 OK



## Meshes and Materials

20.12.2021 19:21:33 
Używa Pan polecenia glBufferData w funkcji frame. To oznacza, że w każdej klatcer alokuje Pan nowy bufor. Reszta OK

3.01.2022 17:04:05 
Ma Pan źle ustwioną kompilację, Zamiast linkować bibliotekę engine, to Pan includuje pliki  Mesh.cpp i Material.cpp co powduje, że używane są złe szadery. Tu jakoś to działa, ale w Textures już nie. 

## Textures

3.01.2022 17:04:16
Ma Pan źle ustwioną kompilację, Zamiast linkować bibliotekę engine, to Pan includuje pliki  Mesh.cpp i Material.cpp co powduje, że używane są złe szadery. Ładowane są shadery z katalogu Textures/shaders/ a powinny z Engine/shaders

