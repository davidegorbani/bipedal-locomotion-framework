/**
 * @file Contact.cpp
 * @authors Giulio Romualdi
 * @copyright 2021 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the BSD-3-Clause license.
 */

#include <BipedalLocomotion/Contacts/Contact.h>
#include <chrono>

using namespace BipedalLocomotion::Contacts;

bool PlannedContact::operator==(const PlannedContact& other) const
{

    bool eq = true;
    eq = eq && this->activationTime == other.activationTime;
    eq = eq && this->name == other.name;
    eq = eq && this->type == other.type;
    eq = eq && this->pose.coeffs() == other.pose.coeffs();
    eq = eq && this->activationTime == other.activationTime;
    eq = eq && this->deactivationTime == other.deactivationTime;
    return eq;
}

std::pair<bool, std::chrono::nanoseconds> EstimatedContact::getContactDetails() const
{
    return std::make_pair(isActive, switchTime);
}

void EstimatedContact::setContactStateStamped(const std::pair<bool, std::chrono::nanoseconds>& pair)
{
    isActive = pair.first;
    switchTime = pair.second;
}
