#pragma once
//--------------------Constans-----------------------
enum class tile_type
{
    field = 0,
    swamp,
    hill,
    mountain,
    num_tile_type
};

enum class resource_type
{
    no_resources = 0,
    gold,
    iron,
    silicon,
    num_res_type
};

//-----------------Helpers------------------
static std::string tile_type_name(tile_type type)
{
    switch (type)
    {
    case tile_type::field:
        return "field";
    case tile_type::swamp:
        return "swamp";
    case tile_type::hill:
        return "hill";
    case tile_type::mountain:
        return "mount";
    default:
        return "Not found";
    }
}

static std::string resource_type_name(resource_type type)
{
    switch (type)
    {
    case resource_type::no_resources:
        return "no res";
    case resource_type::gold:
        return "gold";
    case resource_type::iron:
        return "iron";
    case resource_type::silicon:
        return "silic";
    default:
        return "Not found";
    }
}