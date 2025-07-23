//==============================================================================================
// Originally written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==============================================================================================

#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


int main() {
    hittable_list world;

    // Chão
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    auto mat_U = make_shared<lambertian>(color(0.2, 0.3, 0.8)); // Azul difuso
    auto mat_F = make_shared<metal>(color(0.8, 0.6, 0.2), 0.1); // Dourado polido
    auto mat_S = make_shared<dielectric>(1.5);                   // Vidro
    auto mat_C = make_shared<lambertian>(color(0.8, 0.2, 0.2)); // Vermelho difuso
    auto mat_A = make_shared<metal>(color(0.8, 0.8, 0.8), 0.0); // Prata espelhado
    auto mat_R = make_shared<lambertian>(color(0.2, 0.8, 0.3)); // Verde difuso
    
    const double r = 0.4;

    // Letra U (Azul)
    for (int i=0; i<5; ++i) world.add(make_shared<sphere>(point3(-8, r+i*2*r, 0), r, mat_U));
    world.add(make_shared<sphere>(point3(-7.4, r, 0), r, mat_U));
    world.add(make_shared<sphere>(point3(-6.8, r, 0), r, mat_U));
    for (int i=0; i<5; ++i) world.add(make_shared<sphere>(point3(-6.2, r+i*2*r, 0), r, mat_U));

    // Letra F (Dourado)
    for (int i=0; i<5; ++i) world.add(make_shared<sphere>(point3(-4.2, r+i*2*r, 0), r, mat_F));
    world.add(make_shared<sphere>(point3(-3.6, r+4*2*r, 0), r, mat_F));
    world.add(make_shared<sphere>(point3(-3.0, r+4*2*r, 0), r, mat_F));
    world.add(make_shared<sphere>(point3(-3.6, r+2*2*r, 0), r, mat_F));

    // Letra S (Vidro)
    world.add(make_shared<sphere>(point3(-1.4, r+4*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.8, r+4*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.2, r+4*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(0.4, r+4*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-1.4, r+3*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-1.4, r+2*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.8, r+2*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.2, r+2*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(0.4, r+2*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(0.4, r+1*2*r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-1.4, r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.8, r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(-0.2, r, 0), r, mat_S));
    world.add(make_shared<sphere>(point3(0.4, r, 0), r, mat_S));

    // Letra C (Vermelho)
    world.add(make_shared<sphere>(point3(3.4, r+4*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(2.8, r+4*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(2.2, r+4*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(1.6, r+3*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(1.6, r+2*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(1.6, r+1*2*r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(3.4, r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(2.2, r, 0), r, mat_C));
    world.add(make_shared<sphere>(point3(2.8, r, 0), r, mat_C));

    // Letra A (Prata)
    world.add(make_shared<sphere>(point3(4.8, r+4*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(5.4, r+4*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.0, r+4*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.6, r+4*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(4.8, r+3*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.6, r+3*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(4.8, r+2*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(5.4, r+2*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.0, r+2*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.6, r+2*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.6, r+1*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(4.8, r+1*2*r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(4.8, r, 0), r, mat_A));
    world.add(make_shared<sphere>(point3(6.6, r, 0), r, mat_A));
    
    // Letra R (Verde)
    for (int i=0; i<5; ++i) world.add(make_shared<sphere>(point3(8.4, r+i*2*r, 0), r, mat_R));
    world.add(make_shared<sphere>(point3(9.0, r+4*2*r, 0), r, mat_R));
    world.add(make_shared<sphere>(point3(9.6, r+3*2*r, 0), r, mat_R));
    world.add(make_shared<sphere>(point3(9.0, r+2*2*r, 0), r, mat_R));
    world.add(make_shared<sphere>(point3(9.6, r+1*2*r, 0), r, mat_R));
    world.add(make_shared<sphere>(point3(10.2, r, 0), r, mat_R));

    // Adiciona esferas aleatórias para enriquecer a cena
    for (int i = 0; i < 100; i++) {
        double radius = random_double(0.2, 0.35);
        double z_pos;
        if (random_double() < 0.5) {
            z_pos = random_double(1.0, 15.0); // Na frente das letras
        } else {
            z_pos = random_double(-15.0, -1.0); // Atrás das letras
        }
        point3 center(random_double(-15, 15), radius, z_pos);
        shared_ptr<material> sphere_material;
        auto choose_mat = random_double();
        if (choose_mat < 0.6) {
            auto albedo = color::random() * color::random();
            sphere_material = make_shared<lambertian>(albedo);
        } else if (choose_mat < 0.85) {
            auto albedo = color::random(0.5, 1);
            auto fuzz = random_double(0, 0.3);
            sphere_material = make_shared<metal>(albedo, fuzz);
        } else {
            sphere_material = make_shared<dielectric>(1.5);
        }
        world.add(make_shared<sphere>(center, radius, sphere_material));
    }
    // ==================================================================================
    // FIM DO CÓDIGO DAS LETRAS E ESFERAS
    // ==================================================================================


    // --- Configuração da Câmera ---
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1920;
    cam.samples_per_pixel = 200;
    cam.max_depth         = 50;

    cam.vfov     = 25;
    // Posição da câmera e ponto de foco movidos para a direita para centralizar a palavra
    cam.lookfrom = point3(1.1, 4, 28);   
    cam.lookat   = point3(1.1, 1.5, 0);  
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.4;
    cam.focus_dist    = 28.0;

    cam.render(world);
}