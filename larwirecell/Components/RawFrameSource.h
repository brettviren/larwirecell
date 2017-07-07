/** A wct/ls raw frame source and art::Event visitor. 
 *
 * This is a source from the point of view of WCT.  It's conceptually
 * a sink from the point of view of LArsoft.
 */

#ifndef LARWIRECELL_COMPONENTS_RAWFRAMESOURCE
#define LARWIRECELL_COMPONENTS_RAWFRAMESOURCE

#include "larwirecell/Interfaces/IArtEventVisitor.h"
#include "WireCellIface/IFrameSource.h"

namespace wcls {
    class RawFrameSource : public IArtEventVisitor, // likely needs to be a configurable too.
                           public WireCell::IFrameSource { 
    public:
        RawFrameSource();
        virtual ~RawFrameSource();

        /// IArtEventVisitor 
        virtual void visit(art::Event & event);

        /// IFrameSource
        virtual bool operator()(WireCell::IFrame::pointer& frame);            

    private:
        WireCell::IFrame::pointer m_frame;
    };
}

#endif
