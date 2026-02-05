/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:28:39 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:58:01 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Polymorphism test ===" << std::endl;

    const AAnimal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    //animals[2] = new AAnimal();

    for (int i = 0; i < 2; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 2; i++)
        delete animals[i];

    std::cout << "\n=== Deep copy test ===" << std::endl;

    Cat original;
    Cat copy(original);

    std::cout << "Original sound: ";
    original.makeSound();

    std::cout << "Copy sound: ";
    copy.makeSound();

    return 0;
}