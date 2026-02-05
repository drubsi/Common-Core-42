/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:03:07 by drubio-s          #+#    #+#             */
/*   Updated: 2026/02/05 18:10:57 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{

}
const std::string& Weapon::getType() const
{
	return (this->type);
}
void Weapon::setType(const std::string& newType)
{
	this->type = newType;
}