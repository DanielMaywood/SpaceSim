#pragma once

namespace SpaceSim
{
    /// <summary>
    /// How many Pixels are used to represent
    /// a single meter. (Can be less than one
    /// pixel, i.e. 0.5)
    ///</summary>
    extern double PixelPerM;

    /// <summary>
    /// Scalar to control how much the scroll
    /// wheel zooms in the game view.
    ///</summary>
    extern float ZoomScale;

    /// <summary>
    /// How many ingame seconds happen per
    /// in real life seconds.
    ///</summary>
    extern double TimeScale;

    /// <summary>
    /// Whether or not the bodies should be
    /// drawn to scale.
    ///</summary>
    extern bool ToScaleBodies;
} // namespace SpaceSim